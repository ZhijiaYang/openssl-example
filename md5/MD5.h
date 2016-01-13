/*
 * MD5.h
 *
 *  基于 Openssl crypto 库的加密/解密功能封装
 *
 *  Created on: Mar 11, 2012
 *      Author: yeyuzhen<mail.yeyuzhen@gmail.com>
 */

#include <iostream>
#include <string>

#include <openssl/md5.h>

// 参见 http://blog.csdn.net/lostaway/article/details/7492939
#include "NumSysConvert.h"

/**
* @brief 生成 MD5 摘要
* @author 叶雨珍<yeyzh@ffcs.cn>
* @return 十六进制字符串形式摘要值
*/
inline std::string My_MD5(std::string msg)
{
	std::string result;
	if(msg.empty())
	{
		return result;
	}

	const int digestLen = 16;
	unsigned char digest[digestLen] = {0};
	memset(digest, 0x00, sizeof(digest));

	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, msg.c_str(), msg.size());
	MD5_Final(digest, &ctx);

	result.clear();
	result.append((char *)digest, digestLen);

	return Bin2Hex(result);
}

/**
* @brief MD5 校验
* @author 
* @param digest 十六进制字符串形式摘要
* @return true 校验成功
* @return false 校验失败
*
*/
inline bool My_MD5_Verify(std::string _msg, std::string _digest)
{
	std::string t = My_MD5(_msg);

	// 强制转大写，忽略大小写差异
	for(std::string::iterator iter = _digest.begin();
			iter != _digest.end();
				iter++)
	{
		if(isalpha(*iter))
		{
			*iter = toupper(*iter);
		}
	}

	if(0 == t.compare(_digest))
	{
		return true;
	}
	else
	{
		return false;
	}
}


