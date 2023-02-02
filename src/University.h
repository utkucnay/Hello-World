#pragma once

#include "School.h"

class University :
    public School
{
public:
    enum EDegreeType : uint8_t
    {
        kAssociateDegree,
        kBachelorDegree,
        kGraduateDegree,
        kProfessionalDegree
    };

public:
    University(const std::string& name, const std::string& degree, const EDegreeType& degreeType);

public:
    std::string     _degree;
    EDegreeType     _degreeType;
};

