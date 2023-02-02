#include "Core.h"

#include "University.h"

University::University(const std::string& name, const std::string& degree, const EDegreeType& degreeType) :
	School(name)
{
	_degree = degree;
	_degreeType = degreeType;
	_InherienceTree = kUniversity;
}
