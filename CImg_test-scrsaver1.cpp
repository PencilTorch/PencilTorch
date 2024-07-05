#include "CImg.h"
#include <Windows.h>

// определим константу
#define PI 3.14
// будем использовать пространство имен std и cimg_library для облегчения обращения к методам 
using namespace cimg_library;
using namespace std;

// главная функция программы
int main(int argc, char** argv) {
	int iWidth = GetSystemMetrics(SM_CXSCREEN);  // разрешение экрана по горизонтали
	int iHeight = GetSystemMetrics(SM_CYSCREEN); // разрешение экрана по вертикали
	// объявляем изображения, с которыми будем работать
	// забегая чуть-чуть вперед, скажу, что каждая картинка, полученная в итерации цикла
	// являеся результатом сложения нескольких слоев
	CImg<float> logo, logo_layer_1 = CImg<>(iWidth, iHeight, 1, 1, 0);
	// определим наш первый слой
	// на нем будет изображен текст "Welcome to CImg simple screensaver"
	logo_layer_1.draw_text(120, 5, "Welcome to", CImg<>::vector(255).data(), CImg<>::vector(0).data(), 1, 128);
	logo_layer_1.draw_text(300, 140, "CImg", CImg<>::vector(255).data(), CImg<>::vector(0).data(), 1, 128);
	logo_layer_1.draw_text(250, 285, "simple", CImg<>::vector(255).data(), CImg<>::vector(0).data(), 1, 128);
	logo_layer_1.draw_text(120, 425, "screensaver!", CImg<>::vector(255).data(), CImg<>::vector(0).data(), 1, 128);
	// немного размоем наш слой
	logo_layer_1.blur(6);
	// и нормализуем
	logo_layer_1.normalize(0, 255);
	// создадим еще одно изображение
	CImg<float> logo_layer_2 = CImg<>(logo_layer_1.width(), logo_layer_1.height(), 1, 1, 0);
	// добавим шум к созданному изображению
	logo_layer_2.noise(80, 1);
	// размоем его по вертикали с силой 2
	logo_layer_2.deriche(2, 0, 'y', false);
	// и по горизонтали с силой 10
	logo_layer_2.deriche(10, 0, 'x', false);
	// сложим два слоя и присвоем полученное значение изображению logo
	logo = logo_layer_1 + logo_layer_2 + logo_layer_1;
	// создадим список из нескольких изображений
	// честно говоря, так и не понял, что именно делает метод get_gradient(),
	// в документации это "Compute the list of images, corresponding to the XY-gradients of an image"
	// что-то вроде "вычисляет список изображений, соответствующих XY-градиентам изображения"
	// возвращает значение типа CimgList
	// опытным путем было установлено, что в данном случае создается писок из двух изображений
	CImgList<float> grad = logo.get_gradient();
	// применим ко всему списку фильтр normalize с параметрами (-140,140)
	cimglist_apply(grad, normalize)(-140, 140);
	// и нормализуем слой logo
	logo.normalize(0, 255);
	// создадим переменную, определяющую форму градиента, который вследствии будет соответствовать "спрайту",
	// или изображению, которое будет перемащаться на фоне изображения logo
	CImg<float> light = CImg<>(300 + 2 * logo.width(), 300 + 2 * logo.height());
	// и присвоим ей значения функции Гаусса
	light.draw_gaussian(0.5f * light.width(), 0.5f * light.height(), 80, CImg<>::vector(255).data());
	// наконец создадим спрайт
	CImg<unsigned char> img(logo.width(), logo.height(), 1, 3, 0);
	// создадим экран, на который будем выводить изображение
	CImgDisplay disp(img, " ", true);
	// переключимся в полноэкранный режим
	disp.toggle_fullscreen(false);
	float t = 0;
	// бесконечный цикл, который прерывается по нажатию 'ESC' или 'Q'
	while (!disp.is_closed() && !disp.is_keyQ() && !disp.is_keyESC())
	{
		int pos_x, pos_y, gx, gy;
		float val;
		// вычислим текущее положение перемещаемого изображения
		pos_x = (int)(img.width() / 2 + img.width() * cos(1 * t) / 2);
		pos_y = (int)(img.height() / 2 + img.height() * sin(3 * t) / 2);
		// cimg_forXY - довольно интересный метод, заменяет несколько строк кода
		// подробней - http://cimg.sourceforge.net/reference/group__cimg__loops.html 
		cimg_forXY(img, x, y) {
			// в этом цикле, собственно и происходит наложение спрайта на основное изображение
			gx = (int)grad[0](x, y);
			gy = (int)grad[1](x, y);
			val = 20 + (gx + gy) / 2 + light(light.width() / 2 + pos_x - x + gx, light.height() / 2 + pos_y - y + gy);
			img(x, y, 0) = img(x, y, 1) = img(x, y, 2) = (unsigned char)(val > 255 ? 255 : val < 0 ? 0 : val);
		}
		t = t >= 2 * PI ? 0 : t + 0.02f;
		// выведем изображение на экран
		disp.display(img.draw_image(0, 0, 0, 1, logo, 0.1f));
	}
	return 0;
}