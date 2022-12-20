#include "Response.h"


std::string date_format(const std::string& s) {
	size_t pos1 = s.find('-');
	size_t pos2 = s.find('-', pos1 + 1);
	char buffer[5];
	for (size_t i = 0; i < pos1; ++i)
		buffer[i] = s[i];
	buffer[4] = '\0';
	std::string y(buffer);
	for (size_t i = 0; (pos1 + 1) + i < pos2; ++i)
		buffer[i] = s[(pos1 + 1) + i];
	buffer[2] = '\0';
	std::string m(buffer);
	for (size_t i = 0; (pos2 + 1) + i < s.size(); ++i)
		buffer[i] = s[(pos2 + 1) + i];
	std::string d(buffer);
	return d + "." + m + "." + y;
}
/*-------============GET===========------------*/
std::string Result::get_mitnumber() const {
	return _mitnumber;
}
std::string Result::get_modification() const {
	return _modification;
}
std::string Result::get_mitype() const {
	return _mitype;
}
std::string Result::get_mititle() const {
	return _mititle;
}
std::string Result::get_org_title() const {
	return _org_title;
}
std::string Result::get_number() const {
	return _number;
}
std::string Result::get_verification_date() const {
	return _verification_date;
}
std::string Result::get_valid_date() const {
	return _valid_date;
}
std::string Result::get_result_docnum() const {
	return _result_docnum;
}
std::string Result::get_vri_id() const {
	return _vri_id;
}
std::string Result::get_applicability() const {
	return _applicability ? "Да" : "Нет";
}
bool Result::get_applicability_bool() const {
	return _applicability;
}
//!!!


/*
size_t fillMeansBase(const std::string& str, MeansBase* mb, size_t _bgn) {
	bv_it = 15;
	if (str.find(_border_values[bv_it].first, _bgn) != std::string::npos) {
		mb->_number = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
		++bv_it;
		mb->_title = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
		++bv_it;
		if (str.find("npeURL", _bgn) != std::string::npos)
			mb->_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
		else if (str.find("uveURL", _bgn) != std::string::npos)
			mb->_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
		return _bgn;
	}
	else
		return 0;
}

size_t fillMeansBase_mis(const std::string& str, MeansBase_mis* mb, size_t _bgn) {
	bv_it = 15;
	mb->_number = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	bv_it = 19;
	mb->_mitypeNumber = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	bv_it = 20;
	mb->_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	bv_it = 22;
	mb->_title = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	return _bgn;
}

size_t fillMeansBase_ses(const std::string& str, MeansBase_mis* mb, size_t _bgn) {
	bv_it = 15;
	mb->_number = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	bv_it = 19;
	mb->_mitypeNumber = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	bv_it = 20;
	mb->_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	bv_it = 22;
	mb->_title = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	return _bgn;
}

size_t fillMieta(const std::string& str, Mieta* mi, size_t _bgn) {
	bv_it = 1;
	mi->_regNumber = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_manufactureYear = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_rankCode = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_rankTitle = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_schemaTitle = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	bv_it = 19;
	mi->_mitypeNumber = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_mitypeURL = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_mieta_url = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_mitypeTitle = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_notation = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_modification = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	++bv_it;
	mi->_manufactureNum = pars_str(str, _border_values[bv_it].first, _border_values[bv_it].second, _bgn);
	return _bgn;
}
*/
std::string pars_str(const std::string& str_input, const std::string& str_find, const std::string& str_ender, size_t& it) {
	size_t bgn = str_input.find(str_find, it);
	size_t ender = std::string::npos;
	std::string tmp = "";
	if (bgn != std::string::npos) {
		bgn += str_find.size();
		ender = str_input.find(str_ender, bgn);
		if (ender != std::string::npos) {
			tmp = str_input.substr(bgn, (ender - bgn));
			it = ender + str_ender.size();
		}
	}
	return tmp;
}

std::string VriInfo::get_signPass() const {
	return _applic->_signPass ? "Да" : "Нет";
}

std::string VriInfo::get_signMi() const {
	return _applic->_signMi ? "Да" : "Нет";
}
