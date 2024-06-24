#include "TestSerializer.h"
using namespace std;

#pragma region TestSerializer
void TestSerializer::SerializeTo(string path, const TestSet& set) const
{
	ofstream output(path, ios::trunc);
	if (!output.is_open())
		throw "Cannot open" + path;
	Serialize(output, set);
}

TestSet TestSerializer::DeserializeFrom(string path) const
{
	ifstream input(path, ios::in); 
	if (!input.is_open())
		throw "Cannot open" + path;
	TestSet set = Deserialize(input);
	return set;
}
#pragma endregion

vector<std::string> Split(string s, char seperator)
{
	vector<string> ret;
	size_t i = s.find_first_of(seperator);
	while (i != string::npos)
	{
		ret.emplace_back(s.substr(0, i));
		if (i + 1 >= s.length())
		{
			s = "";
			break;
		}
		else
			s = s.substr(i + 1);
		i = s.find_first_of(seperator);
	}
	if (s != "")
	{
		ret.push_back(s);
	}
	return ret;
}
