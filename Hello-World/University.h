#pragma once

#include "School.h"

class University :
    public School
{
public:
    enum DegreeType : uint8_t
    {
        kAssociateDegree,
        kBachelorDegree,
        kGraduateDegree,
        kProfessionalDegree
    };

public:
    University(const std::string& name, const std::string& degree, const DegreeType& degreeType);

public:
    std::string     _degree;
    DegreeType      _degreeType;
};

