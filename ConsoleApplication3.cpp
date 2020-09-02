// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <ctime>
#include <cstdarg>
#include <vector>
#include <chrono>
#include <iostream>

int global; //static, const and constexpr global variables have internal linkaging
std::vector<std::string> parseArgs(std::string args);

class Timer {
public:
	Timer() {
		auto m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	~Timer() {
		Stop();
	}

	void Stop() {
		auto endTimePoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
		auto duration = end - start;

		std::cout << duration << "µs" << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};

int main()
{
	int sum = 0;

	for (int i = 0; i < 1000; ++i) {
		auto m_StartTimePoint = std::chrono::high_resolution_clock::now();
		parseArgs("  a b  c   d  ");

		auto endTimePoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
		auto duration = end - start;

		std::cout << duration << "us" << std::endl;
		sum += duration;
	}
	std::cout << "avg. time:" <<  sum / 1000 << "us";
	std::cin.get();
}


std::vector<std::string> parseArgs(std::string args) {
	std::vector<std::string> seperatedArgs;
	if (args.size() == 0) {
		return seperatedArgs;
	}

	//remove proceding spaces
	//how in the actual fuck does this work
	for (int i = args.size(); i > 0; --i) {
		if (isspace(args[i - 1])) {
			args.erase(i - 1, 1);
		}
		else {
			break;
		}
	}
	//remove preceding spaces
	int upto = 0;
	for (int i = 0; i < args.size()-1; ++i) {
		if (isspace(args[0])) {
			args.erase(0, 1);
		}
		else {
			break;
		}
	}

	//remove duplicate spaces

	std::vector<int> toErase;

	bool lastCharWS = false;
	if (isspace(args[0])) {
		lastCharWS = true;
		toErase.push_back(0);
	}

	for (int i = 1; i < args.length(); ++i) {

		bool wasSpace = isspace(args[i]);

		if (lastCharWS && isspace(args[i])) {
			toErase.push_back(i);
			lastCharWS = true;
		}
		
		if (wasSpace) {
			lastCharWS = true;
		}
		else {
			lastCharWS = false;
		}

	}

	for (int i = toErase.size()-1; i >= 0; --i) {
		args.erase(toErase[i], 1);
	}
	
	//delimiter " " (space)
	std::vector<std::size_t> deliminers;
	for (int i = 0; i < args.length(); ++i) {

		if (isspace(args[i])) {
			deliminers.push_back(i);
		}
	}
	//now to actualy cut out the variables
	//alot of boilerplate but oh well
	//return seperatedArgs;
	if (deliminers.empty()) {

		seperatedArgs.push_back(args);

	}
	else if (deliminers.size() == 1) {

		seperatedArgs.push_back(args.substr(0, deliminers[0]));
		seperatedArgs.push_back(args.substr(deliminers[deliminers.size() - 1] + 1, args.length() - deliminers[deliminers.size() - 1]));

	}
	else {

		seperatedArgs.push_back(args.substr(0, deliminers[0]));
		for (int i = 0; i < (deliminers.size() - 1); ++i) {
			seperatedArgs.push_back(args.substr(deliminers[i] + 1, (deliminers[i + 1]) - (deliminers[i] + 1)));
		}
		seperatedArgs.push_back(args.substr(deliminers[deliminers.size() - 1] + 1, args.length() - deliminers[deliminers.size() - 1]));

	}

	return seperatedArgs;
}

