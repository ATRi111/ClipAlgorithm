#pragma once
#include<iostream>
#include<fstream>
#include<ios>
#include<string>
#include"Test.h"

class TestSerializer
{
public:
	void SerializeTo(std::string path, const TestSet& set) const;
	virtual void Serialize(std::ofstream& stream, const TestSet& set) const = 0;
	TestSet DeserializeFrom(std::string path) const;
	virtual TestSet Deserialize(std::ifstream& stream) const = 0;
};

std::vector<std::string> Split(std::string s, char seperator);