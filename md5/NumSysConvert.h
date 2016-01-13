/*
 * NumSysConvert.h
 *
 *  基于 Openssl crypto 库的加密/解密功能封装
 *
 *  Created on: Mar 11, 2012
 *      Author: yeyuzhen<mail.yeyuzhen@gmail.com>
 */

#ifndef NUMSYSCONVERT_H_
#define NUMSYSCONVERT_H_

#include <iostream>
#include <string>

#include <openssl/x509v3.h>

/**
* @brief 二进制转十六进制
* @author 
*/
inline std::string Bin2Hex(std::string _in)
{
	std::string result;
	const char hexdig[] = "0123456789ABCDEF";

	if(_in.empty())
	{
		return result;
	}

	result.clear();
	for(std::string::iterator i = _in.begin(); i != _in.end(); i++)
	{
		result.append(1, hexdig[(*i >> 4) & 0xf]);  //留下高四位
		result.append(1, hexdig[(*i & 0xf)]);  //留下低四位

	}

	return result;
}


/**
* @brief 十六进制转二进制
* @author 
*/
inline std::string Hex2Bin(std::string _in)
{
	long int binSize = 0;
	unsigned char *t = NULL;
	std::string result;

	t = string_to_hex((char *)_in.c_str(), &binSize);  // 位于 x509v3.h

	result.clear();
	result.append((char *)t, binSize);

	return result;
}

#endif /* NUMSYSCONVERT_H_ */
