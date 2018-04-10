#include "stdafx.h"
#include <cctype>
#include "Simplificator.h"

Simplificator::Simplificator()
{
}



void Simplificator::simplify(std::string &str) 
{
//	str.erase(remove_if(str.begin(), str.end(), ' '));
	std::string pp = "++";
	std::string mm = "--";
	std::string pm = "+-";
	std::string mp = "-+";
	while (str.find(pm) != std::string::npos || str.find(mp) != std::string::npos
		|| str.find(pp) != std::string::npos || str.find(mm) != std::string::npos)
	{
		if (str.find(mp) != std::string::npos)
		str.erase(str.find(mp) + 1, 1);
		if (str.find(pm) != std::string::npos)
		str.erase(str.find(pm), 1);
		if (str.find(pp) != std::string::npos) 
			str.erase(str.find(pp), 1);
		if (str.find(mm) != std::string::npos)
			str.replace(str.find(mm), 2, "+");
	}
}

Simplificator::~Simplificator()
{
}
