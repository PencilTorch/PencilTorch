#pragma once
#include <vector>
#include <algorithm>

namespace QuestCLRProject {

	struct TestPassage {
		int test_id;
		std::vector<std::pair<int, bool>> vPassage;
	};


	class LogFile {
	public:
		LogFile(int a_id) {
			autirize_id = a_id;
		}
		int getAutorizeID() {
			return autirize_id;
		}
		std::vector<std::pair<int, bool>>* getTestPassage(int t_id) {
			auto it = _vTP.end();
			it = std::find_if(_vTP.begin(), _vTP.end(), [&](const TestPassage& s) { return s.test_id == t_id; });
			if (it != _vTP.end())
				return &it->vPassage;
			else {
				std::vector<std::pair<int, bool>> *vPNULL = nullptr;
				return vPNULL;
			}
		}
		
		void setTP(int t_id, int num_q, bool yon) {
			auto it1 = _vTP.end();
			it1 = std::find_if(_vTP.begin(), _vTP.end(), [&](const TestPassage& s) { return s.test_id == t_id; });
			if (it1 != _vTP.end()) {
				auto it2 = std::find_if(it1->vPassage.begin(), it1->vPassage.end(), [&](const std::pair<int, bool>& pp) { return pp.first == num_q; });
				if (it2 != it1->vPassage.end())
					it2->second = yon;
				else
					it1->vPassage.emplace_back(num_q, yon);
			} 
			else {
				TestPassage tmpTP;
				tmpTP.test_id = t_id;
				tmpTP.vPassage.emplace_back(num_q, yon);
				_vTP.push_back(tmpTP);
			}
		}
	private:
		int autirize_id;
		std::vector<TestPassage> _vTP;
	};
}



