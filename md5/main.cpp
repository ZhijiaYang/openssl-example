/*
 * main.cpp
 *   
 *   MD5 摘要测试
 *
 */

#include <iostream>
#include <string>

#include "MD5.h"

int main(int argc, char *argv[])
{
	std::string msg("I'am test message!!!");
	std::string digest = My_MD5(msg);
	std::cout << "Digest:" << digest << std::endl;
	
	std::string expectDigest("07B12819CB3AA62F9B45072B414B0512");
	if(!expectDigest.compare(My_MD5(msg)))
	{
		std::cout << "MD5 Verify Success!!" << std::endl;
	}
	else
	{
		std::cout << "MD5 Verify Fail!!" << std::endl;
	}
	
	return 0;
}


