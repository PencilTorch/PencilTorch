#pragma once
#include <string>
#include <vector>

/*
Средства поверки

npe - Государственные первичные эталоны
uve - Эталоны единицы величины
ses - Стандартные образцы
mieta - Средства измерений, применяемые в качестве эталона
mis - Средства измерений, применяемые при поверке
reagent - Вещество (материал), применяемый при поверке
*/

// вектор граничных меток для парса строки
const std::vector <std::pair<std::string, std::string>> _border_values{
		{"mitypeURL\":\"","\","}, {"regNumber\":\"","\","},  {"manufactureYear\":",","},
		{"rankCode\":\"","\","}, {"rankTitle\":\"","\","},  {"schemaTitle\":\"","\""},
		{"organization\":\"","\","}, {"signCipher\":\"","\","},  {"miOwner\":\"","\","},
		{"docTitle\":\"","\","}, {"vriType\":\"","\","},  {"certNum\":\"","\","},
		{"stickerNum\":\"","\","}, {"signPass\":",","},  {"signMi\":","}"},
		{"number\":\"","\""}, {"title\":\"","\""},  {"npeURL\":\"","\""},
		{"uveURL\":\"","\""}, {"mitypeNumber\":\"","\","},  {"mitypeURL\":\"","\""},
		{"mietaURL\":\"","\""}, {"mitypeTitle\":\"","\","},  {"notation\":\"","\","},
		{"modification\":\"","\","}, {"manufactureNum\":\"","\","},  {"structure\":\"","\","},
		{"briefIndicator\":",","}, {"briefCharacteristics\":\"","\""},  {"mimetype\":\"","\","},
		{"filename\":\"","\","}, {"doc_id\":","}"},  {"additional_info\":\"","\""},
		{"seURL\":\"","\","}, {"type\":\"","\","} };

static size_t bv_it; //итератор для _border_values, нужен в парсе возвращаемой строки в запросе полных сведений по конкретному СИ

std::string date_format(const std::string& s);

class Result {
public:
	Result() {}
	void setResult(const std::string& mitnumber, const std::string& modification, const std::string& number,
		const std::string& valid_date, const std::string& result_docum, const std::string& mitype,
		const std::string& mititle, const std::string& org_title, const std::string& applicability,
		const std::string& vri_id, const std::string& verification_date) {
		_mitnumber = mitnumber;
		_modification = modification;
		_number = number;
		_valid_date = date_format(valid_date);
		_result_docnum = result_docum;
		_mitype = mitype;
		_mititle = mititle;
		_org_title = org_title;
		_applicability = (applicability == "true") ? 1 : 0;
		_vri_id = vri_id;
		_verification_date = date_format(verification_date);
	}

	std::string get_mitnumber() const;
	std::string get_modification() const;
	std::string get_mitype() const;
	std::string get_mititle() const;
	std::string get_org_title() const;
	std::string get_number() const;
	std::string get_verification_date() const;
	std::string get_valid_date() const;
	std::string get_result_docnum() const;
	std::string get_vri_id() const;
	std::string get_applicability() const;
	bool get_applicability_bool() const;
private:
	std::string _mitnumber;						//ГР
	std::string _modification;					//модификация
	std::string _mitype;						//тип
	std::string _mititle;						//наименование СИ
	std::string _number;						//заводской номер
	std::string _result_docnum;					//результирующий документ
	std::string _org_title;						//организация поверитель
	std::string _verification_date;				//дата поверки
	std::string _valid_date;					//годно до
	bool _applicability;						//годность СИ
	std::string _vri_id;						//id поверки
};

struct Eta {
	std::string _regNumber = "";
	std::string _manufactureYear = "";
	std::string _rankCode = "";
	std::string _rankTitle = "";
	std::string _schemaTitle = "";
};

struct Applicable {
	std::string _certNum = "";
	std::string _stickerNum = "";
	bool _signPass = false;
	bool _signMi = false;
};

class VriInfo {
public:
	VriInfo() {
		_applic = new Applicable();
		_organization = "";
		_signCipher = "";
		_miOwner = "";
		_docTitle = "";
		_vriType = "";
	}
	std::string get_signPass() const;
	std::string get_signMi() const;
	~VriInfo() {
		delete _applic;
		_applic = nullptr;
	}

	std::string _organization;
	std::string _signCipher;
	std::string _miOwner;
	std::string _docTitle;
	std::string _vriType;
	Applicable* _applic = nullptr;
};

//for  means
struct MeansBase {
	std::string _number = "";
	std::string _title = "";
	std::string _url = "";
};

struct MeansBase_mis : public MeansBase {
	std::string _mitypeNumber = "";
};

struct MeansBase_ses : public MeansBase {
	std::string _manufactureYear = "";
};

struct Reagent {
	std::string _number = "";
	std::string _type = "";
	std::string _title = "";
};

struct Mieta : public Eta {
	std::string _mieta_url = "";
	std::string _mitypeNumber = "";
	std::string _mitypeURL = "";
	std::string _mitypeTitle = "";
	std::string _notation = "";
	std::string _modification = "";
	std::string _manufactureNum = "";
};

struct Means {
	std::vector<MeansBase*> _npe;
	std::vector<MeansBase*> _uve;
	std::vector<MeansBase_mis*> _mis;
	std::vector<MeansBase_ses*> _ses;
	std::vector<Mieta*> _mieta;
	std::vector<Reagent*> _reagents;
	~Means() {
		if (!_npe.empty()) {
			for (std::vector<MeansBase*>::iterator ib = _npe.begin(); ib != _npe.end(); ++ib)
				delete* ib;
			_npe.resize(0);
		}
		if (!_uve.empty()) {
			for (std::vector<MeansBase*>::iterator ib = _uve.begin(); ib != _uve.end(); ++ib)
				delete* ib;
			_uve.resize(0);
		}
		if (!_mis.empty()) {
			for (std::vector<MeansBase_mis*>::iterator ib = _mis.begin(); ib != _mis.end(); ++ib)
				delete* ib;
			_mis.resize(0);
		}
		if (!_ses.empty()) {
			for (std::vector<MeansBase_ses*>::iterator ib = _ses.begin(); ib != _ses.end(); ++ib)
				delete* ib;
			_ses.resize(0);
		}
		if (!_mieta.empty()) {
			for (std::vector<Mieta*>::iterator ib = _mieta.begin(); ib != _mieta.end(); ++ib)
				delete* ib;
			_mieta.resize(0);
		}
		if (!_reagents.empty()) {
			for (std::vector<Reagent*>::iterator ib = _reagents.begin(); ib != _reagents.end(); ++ib)
				delete* ib;
			_reagents.resize(0);
		}
	}
};

struct Protocol {
	std::string _title = "";
	std::string _mimetype = "";
	std::string _filename = "";
	std::string _doc_id = "";
};

struct OverInfo {
	std::string _structure = "";
	bool _briefIndicator = false;
	std::string _briefCharacteristics = "";
	Protocol* _prt = nullptr;
	std::string _additional_info = "";
	~OverInfo() {
		if (_prt != nullptr) {
			delete _prt;
			_prt = nullptr;
		}
	}
};

class Response {
public:
	Response() {
		_result = new Result();
		_vri_info = new VriInfo();
		_means = new Means();
		_over_info = new OverInfo();
		_mitypeURL = "";
		
	}
	~Response() {
		delete _result;
		delete _vri_info;
		delete _means;
		delete _over_info;
		if (_eta != nullptr) {
			delete _eta;
			_eta = nullptr;
		}
	}

	Result* _result = nullptr;
	Eta* _eta = nullptr;
	VriInfo* _vri_info = nullptr;
	Means* _means = nullptr;
	OverInfo* _over_info = nullptr;
	std::string _mitypeURL;						//ссылка на тип
};
/*
size_t fillMeansBase(const std::string& str, MeansBase* mb, size_t _bgn);
size_t fillMeansBase_mis(const std::string& str, MeansBase_mis* mb, size_t _bgn);
size_t fillMeansBase_ses(const std::string& str, MeansBase_mis* mb, size_t _bgn);
size_t fillMieta(const std::string& str, Mieta* mi, size_t _bgn);
*/
std::string pars_str(const std::string& str_input, const std::string& str_find, const std::string& str_ender, size_t& it);