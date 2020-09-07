/**************************************************************************

�������ڣ�2020��9��7��
˵����Ŀǰ�ӿڴ󲿷���ɣ���̬��ȡ���̱���md5�Ĳ��ֻ�û���
ע�⣺
�뽫C++���Ա�׼����Ϊstd:C++17!!!!!!!!!!
��һ��Ҫ����Ϊ��̬���룬
�����ʵ�ֶ�̬dll����Ļ���Ҳ���Ƕ��߳�dll/MD  ���̵߳���dll/MDd���Ļ�
���Լ���githuub�� CJsonObject����⣬�� openssl�� ��
�Լ�����滻Ȼ�������� libcrypto.libϵ�е�Ԥ�����ɾ��

���ߣ�Lains
��ϵ��ʽ��
lainswork@qq.com

�����˵����
����һ���������л�����������֤�Խ���;�����ӣ���Ҳ����ֱ��ʹ�������жԽ�
������������֤������http://www.huweidun.cn/

˵����



**************************************************************************/


#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <objbase.h>
#include <map>
#include <cmath>
#include"XorString.h"

#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")


//ʹ��CJsonObject�����json�ִ���ʽ����ʹ�ã�����github����CJsonObject
#include "CJsonObject.hpp"

//md5������
#include "md5.h"

//Base64�������
#include "Base64.h"

//url�������
#include "url_encoder.h"

//ʹ�ÿ�Դ��openssl��des������
#include <openssl/des.h>
#include <openssl/aes.h>
#include <openssl/pem.h>
#include <openssl/err.h>

//������ͷ�ļ�
#include "HardWare.h"


//Ԥ����꣬�ֱ��Ӧdebug 32 ��debug 64 ��Release 32�� Release64
#ifdef _DEBUG  
#ifndef _WIN64  
#pragma comment(lib, "libcrypto_Debug_32.lib")
#else  
#pragma comment(lib, "libcrypto_Debug_64.lib")
#endif  
#else  
#ifndef _WIN64  
#pragma comment(lib, "libcrypto_Release_32.lib")
#else  
#pragma comment(lib, "libcrypto_Release_64.lib")

#endif  
#endif




#define GUID_LEN 64
#define OUT
#define IN

namespace NETWORK 
{
	struct Info
	{
		//��
		std::string Key;
		//ֵ
		std::string Value;
	};

	//��ҳ�������
	enum LAINSPATTERN
	{
		GET = 0,
		POST = 1
	};
	//�۵㷽ʽ
	enum DEDUCTPOINTMODE
	{
		//һ��һ��ip���߻�����ֻ��һ��
		ONEDAY_ONCE,
		//ÿ�ε�¼����۵㣨ps��ò��ûɶ�ã�
		EVERYTIME_ONCE,
	};

	class CHwdNetWork
	{

	public:
		//���Ĵ�����Ϣ�����ӿڷ���ΪfalseʱLastErroMsg���������ԭ��
		std::string GetLastErroMsg() 
		{
			return aes_256_cbc_decode(LastErroMsg, this->�����ִ�����key);
		}
		//����
		std::string GetNotice()
		{
			return aes_256_cbc_decode(notice, this->�����ִ�����key);
		}
		//�������
		std::string GetName()
		{
			return aes_256_cbc_decode(name, this->�����ִ�����key);
		}
		//�汾��
		std::string GetVersion()
		{
			return aes_256_cbc_decode(version, this->�����ִ�����key);
		}
		//�ͷ�QQ
		std::string GetQq()
		{
			return aes_256_cbc_decode(qq, this->�����ִ�����key);
		}
		//���������ַ
		std::string GetDownloadurl()
		{
			return aes_256_cbc_decode(downloadurl, this->�����ִ�����key);
		}
		//���������ַ
		std::string GetUpdateurl()
		{
			return aes_256_cbc_decode(updateurl, this->�����ִ�����key);
		}
		//�û�������,������Ϸ�ŵ�
		std::string Getbind()
		{
			return aes_256_cbc_decode(bind, this->�����ִ�����key);
		}
		//����ʱ��
		std::string GetEndtime()
		{
			return aes_256_cbc_decode(endtime, this->�����ִ�����key);
		}
		//����ʱ���
		time_t GetEndTime_time_t()
		{
			return ����ʱ���;
		}
		//��ǰ����ʱ��
		time_t GetInternetTime_time_t()
		{
			return ��ǰ����ʱ���;
		}
		//�������
		std::string GetPoint()
		{
			return aes_256_cbc_decode(point, this->�����ִ�����key);
		}
		//�������
		size_t GetPoint_size_t()
		{
			return �������;
		}
		//�û��Զ��峣��
		std::string GetPara()
		{
			return aes_256_cbc_decode(para, this->�����ִ�����key);
		}
		//����Զ��峣��
		std::string GetSoftpara()
		{
			return aes_256_cbc_decode(softpara, this->�����ִ�����key);
		}
		//�û���
		std::string GetUser()
		{
			return aes_256_cbc_decode(user, this->�����ִ�����key);
		}
		//����
		std::string GetPass()
		{
			return aes_256_cbc_decode(pass, this->�����ִ�����key);
		}
		//�˻����
		std::string GetBalance()
		{
			return aes_256_cbc_decode(balance, this->�����ִ�����key);
		}


	private:
		//���Ĵ�����Ϣ�����ӿڷ���ΪfalseʱLastErroMsg���������ԭ��
		std::string LastErroMsg;
		//����
		std::string notice;
		//�������
		std::string name;
		//�汾��
		std::string version;
		//�ͷ�QQ
		std::string qq;
		//���������ַ
		std::string downloadurl;
		//���������ַ
		std::string updateurl;
		//�û�������,������Ϸ�ŵ�
		std::string bind;
		//����ʱ��
		std::string endtime;
		//����ʱ���
		time_t ����ʱ���;
		//��ǰ����ʱ��
		time_t ��ǰ����ʱ���;
		//�������
		std::string point;
		//�������
		size_t �������;
		//�û��Զ��峣��
		std::string para;
		//����Զ��峣��
		std::string softpara;
		//�û���
		std::string user;
		//����
		std::string pass;
		//�˻����
		std::string balance;
	public:
		CHwdNetWork(
			IN std::string _Key/*ͨѶ��Կ*/,
			IN std::string _Sid/*���sid*/,
			IN std::string _ModuleMd5/*������Ȩ����*/,
			IN std::string _WebKey/*������Ȩ����*/,
			IN std::string _SignRuleClient/*�ͻ���sign����*/,
			IN std::string _SignRuleServer/*�ͻ���sign����*/,
			IN WORD _Port/*�������˿�*/,
			IN std::string _Domain/*��������ַ*/,
			IN std::string _PageAddr/*����ҳ*/)
		{
			//�̶�������ֵ
			Key = _Key;
			Sid = _Sid;
			Md5_3 = _ModuleMd5;
			WebKey = _WebKey;
			SignRuleClient = _SignRuleClient;
			SignRuleServer = _SignRuleServer;
			Domain = _Domain;
			PageAddr = _PageAddr;
			Port = _Port;

			//��ǰ����MD5ֵ,�������У��MD5,���ֵ����,���ڳ�������ʱ��̬��ȡ����MD5ֵ.

			//��exe�Ļ��ʺʹ�С����ȥ����ȡ�������md5 ȱ�ٹ���
			Md5_2 = "";
			/*std::cout << "����md5��" << Md5_2 <<std::endl;
			std::cout << std::endl;
			*/
			/*std::cout << "��ȡ������"  << std::endl;
			std::cout << std::endl; system("pause");*/


			//������
			Mac_code = MD5(HardWare().strAllMacInfo).toString();

			/*std::cout << "�����������룺" << Mac_code << std::endl;
			std::cout << std::endl; system("pause");*/


			ClientId = generate();
			/*std::cout << "��ʼ�ֽ���Կ" << std::endl;
			std::cout << std::endl; system("pause");*/
			//�ֽ���Կ
			�ͻ�����Կ = Key.substr(0, 8);
			std::string ��iv���� = Key.substr(24, 8);
			for (size_t i = 0; i < 8; i++)
			{
				�ͻ���IV����[i] = ��iv����[i];
			}

			�������Կ = Key.substr(8, 8);
			std::string ��iv���� = Key.substr(16, 8);
			for (size_t i = 0; i < 8; i++)
			{
				�����IV����[i] = ��iv����[i];
			}
			//����һ��AES��Կ�������Ա��ر�������ݣ��ı����ݣ����м��ܣ���ֹ��od����debug�б�������
			//��Կ��Ҫ�趨Ϊ32λ
			auto rand_str = _GetRandStr(32);
			char* rand_Key = rand_str.get();
			�����ִ�����key = std::string(rand_Key);
			/*std::cout << "���캯������" << std::endl;
			std::cout << std::endl; system("pause");*/
		}
		~CHwdNetWork()
		{

		}

		//��ʼ����֤
		bool Init()
		{
			Info info;
			info.Key = xorstr("action").crypt_get();
			info.Value = xorstr("init").crypt_get();
			std::vector<Info> test;
			test.push_back(info);

			neb::CJsonObject retJson;
			if (HttpRequest(test, retJson))
			{
				std::string codestr;
				retJson.Get(xorstr("code").crypt_get(), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(xorstr("result").crypt_get(), result);

					result.Get(xorstr("notice").crypt_get(), this->notice);
					result.Get(xorstr("name").crypt_get(), this->name);
					result.Get(xorstr("version").crypt_get(), this->version);
					result.Get(xorstr("qq").crypt_get(), this->qq);
					result.Get(xorstr("downloadurl").crypt_get(), this->downloadurl);
					result.Get(xorstr("updateurl").crypt_get(), this->updateurl);

					this->notice = aes_256_cbc_encode(notice, �����ִ�����key);
					this->name = aes_256_cbc_encode(name, �����ִ�����key);
					this->version = aes_256_cbc_encode(version, �����ִ�����key);
					this->qq = aes_256_cbc_encode(qq, �����ִ�����key);
					this->downloadurl = aes_256_cbc_encode(downloadurl, �����ִ�����key);
					this->updateurl = aes_256_cbc_encode(updateurl, �����ִ�����key);

					return true;
				}
				else
				{
					LastErroMsg = aes_256_cbc_encode(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = aes_256_cbc_encode(xorstr("����ʧ�ܣ�").crypt_get(), �����ִ�����key);
				return false;
			}

		}
		//�û���¼
		bool UserLogin(IN std::string username/*�û���*/, IN std::string password/*����*/)
		{
			//action=login&user=�û���&pwd=����&code=��֤��
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = xorstr("action").crypt_get();
			api.Value = xorstr("login").crypt_get();
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = xorstr("user").crypt_get();
			Var1.Value = username;
			PostMsgInfo.push_back(Var1);
			Info Var2;
			Var2.Key = xorstr("pwd").crypt_get();
			Var2.Value = password;
			PostMsgInfo.push_back(Var2);


			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(xorstr("code").crypt_get(), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(xorstr("result").crypt_get(), result);

					result.Get(xorstr("bind").crypt_get(), bind);
					result.Get(xorstr("endtime").crypt_get(), endtime);
					����ʱ��� = StringToDatetime(endtime);
					result.Get(xorstr("para").crypt_get(), para);
					result.Get(xorstr("point").crypt_get(), point);
					������� = atoi(point.c_str());
					result.Get(xorstr("softpara").crypt_get(), softpara);
					result.Get(xorstr("user").crypt_get(), user);

					this->bind = aes_256_cbc_encode(this->bind, �����ִ�����key);
					this->endtime = aes_256_cbc_encode(this->endtime, �����ִ�����key);
					this->para = aes_256_cbc_encode(this->para, �����ִ�����key);
					this->point = aes_256_cbc_encode(this->point, �����ִ�����key);
					this->softpara = aes_256_cbc_encode(this->softpara, �����ִ�����key);
					this->user = aes_256_cbc_encode(this->user, �����ִ�����key);
					pass = password;
					this->pass = aes_256_cbc_encode(password, �����ִ�����key);
					return true;
				}
				else
				{
					LastErroMsg = aes_256_cbc_encode(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = aes_256_cbc_encode(xorstr("����ʧ�ܣ�").crypt_get(), �����ִ�����key);
				return false;
			}
			return false;
		}
		//������
		bool HeartBeat()
		{
			//action=heartbeat&user=�û���
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = xorstr("action").crypt_get();
			api.Value = xorstr("heartbeat").crypt_get();
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = xorstr("user").crypt_get();
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);



			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(xorstr("code").crypt_get(), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(xorstr("result").crypt_get(), result);

					result.Get(xorstr("bind").crypt_get(), bind);
					result.Get(xorstr("endtime").crypt_get(), endtime);
					����ʱ��� = StringToDatetime(endtime);
					result.Get(xorstr("para").crypt_get(), para);
					result.Get(xorstr("point").crypt_get(), point);
					������� = atoi(point.c_str());
					result.Get(xorstr("softpara").crypt_get(), softpara);

					bind = aes_256_cbc_encode(bind, �����ִ�����key);
					endtime = aes_256_cbc_encode(endtime, �����ִ�����key);
					para = aes_256_cbc_encode(para, �����ִ�����key);
					point = aes_256_cbc_encode(point, �����ִ�����key);
					softpara = aes_256_cbc_encode(softpara, �����ִ�����key);


					return true;
				}
				else
				{

					LastErroMsg = aes_256_cbc_encode(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = aes_256_cbc_encode(xorstr("����ʧ�ܣ�").crypt_get(), �����ִ�����key);
				return false;
			}
			return false;
		}
		//���û���Ϣ
		bool BindStr(IN std::string str/*������*/)
		{
			//action=bindstr&user=�û���&pwd=����&str=������
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = xorstr("action").crypt_get();
			api.Value = xorstr("bindstr").crypt_get();
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = xorstr("user").crypt_get();
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);
			Info Var2;
			Var2.Key = xorstr("pwd").crypt_get();
			Var2.Value = this->GetPass();
			PostMsgInfo.push_back(Var2);
			Info Var3;
			Var3.Key = xorstr("str").crypt_get();
			Var3.Value = str;
			PostMsgInfo.push_back(Var3);


			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(xorstr("code").crypt_get(), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					return true;
				}
				else
				{
					LastErroMsg = aes_256_cbc_encode(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = aes_256_cbc_encode(xorstr("����ʧ�ܣ�").crypt_get(), �����ִ�����key);
				return false;
			}
			return false;
		}
		//�󶨻�����
		bool BindMac(IN std::string username/*�û���*/)
		{
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = xorstr("action").crypt_get();
			api.Value = xorstr("bind").crypt_get();
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = xorstr("user").crypt_get();
			Var1.Value = username;
			PostMsgInfo.push_back(Var1);


			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(xorstr("code").crypt_get(), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					return true;
				}
				else
				{
					LastErroMsg = aes_256_cbc_encode(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = aes_256_cbc_encode(xorstr("����ʧ�ܣ�").crypt_get(), �����ִ�����key);
				return false;
			}
			return false;
		}
		//��ֵ
		bool RechArge(IN std::string username/*�û���*/, IN std::string cdkey/*��ֵ��*/)
		{
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = xorstr("action").crypt_get();
			api.Value = xorstr("recharge").crypt_get();
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = xorstr("user").crypt_get();
			Var1.Value = username;
			PostMsgInfo.push_back(Var1);
			Info Var2;
			Var2.Key = xorstr("card").crypt_get();
			Var2.Value = cdkey;
			PostMsgInfo.push_back(Var2);


			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(xorstr("code").crypt_get(), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(xorstr("result").crypt_get(), result);

					result.Get(xorstr("balance").crypt_get(), balance);
					result.Get(xorstr("endtime").crypt_get(), endtime);
					����ʱ��� = StringToDatetime(endtime);
					result.Get(xorstr("point").crypt_get(), point);
					������� = atoi(point.c_str());

					balance = aes_256_cbc_encode(balance, �����ִ�����key);
					endtime = aes_256_cbc_encode(endtime, �����ִ�����key);
					point = aes_256_cbc_encode(point, �����ִ�����key);

					return true;
				}
				else
				{
					LastErroMsg = aes_256_cbc_encode(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = aes_256_cbc_encode(xorstr("����ʧ�ܣ�").crypt_get(), �����ִ�����key);
				return false;
			}
			return false;
		}
		//�۵�
		bool DeductPoint(IN std::string number/*�۳�����*/, IN DEDUCTPOINTMODE mode/*�۵㷽ʽ*/)
		{
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = xorstr("action").crypt_get();
			api.Value = xorstr("deductpoint").crypt_get();
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = xorstr("user").crypt_get();
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);
			Info Var2;
			Var2.Key = xorstr("num").crypt_get();
			Var2.Value = number;
			PostMsgInfo.push_back(Var2);

			Info Var3;
			if (mode == DEDUCTPOINTMODE::ONEDAY_ONCE)
			{

				Var3.Key = xorstr("filter").crypt_get();
				Var3.Value = xorstr("1").crypt_get();
				PostMsgInfo.push_back(Var3);
				Info Var4;
				Var4.Key = xorstr("msg").crypt_get();
				time_t today = time(NULL);
				Var4.Value = Mac_code + DatetimeToString(today, true, false, false, false);
				PostMsgInfo.push_back(Var4);
			}
			else
			{
				Var3.Key = xorstr("filter").crypt_get();
				Var3.Value = xorstr("0").crypt_get();
				PostMsgInfo.push_back(Var3);
			}

			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(xorstr("code").crypt_get(), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(xorstr("result").crypt_get(), result);
					result.Get(xorstr("point").crypt_get(), point);
					������� = atoi(point.c_str());
					point = aes_256_cbc_encode(point, �����ִ�����key);

					return true;
				}
				else
				{

					LastErroMsg = aes_256_cbc_encode(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = aes_256_cbc_encode(xorstr("����ʧ�ܣ�").crypt_get(), �����ִ�����key);
				return false;
			}
			return false;
		}
		//��ʱ
		bool DeductTime(IN std::string number/*�۳�����*/)
		{
			//action=deducttime&user=��ʱ�˺�&num=�۳�����&msg=��ʱ��ע&filter=0
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = xorstr("action").crypt_get();
			api.Value = xorstr("deducttime").crypt_get();
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = xorstr("user").crypt_get();
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);
			Info Var3;
			Var3.Key = xorstr("num").crypt_get();
			Var3.Value = number;
			PostMsgInfo.push_back(Var3);
			Info Var4;
			Var4.Key = xorstr("msg").crypt_get();
			Var4.Value = xorstr("�۵�����:").crypt_get() + DatetimeToString(time(NULL), true, true, true, false);
			PostMsgInfo.push_back(Var4);
			Info Var5;
			Var5.Key = xorstr("filter").crypt_get();
			Var5.Value = xorstr("0").crypt_get();
			PostMsgInfo.push_back(Var5);

			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(xorstr("code").crypt_get(), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(xorstr("result").crypt_get(), result);

					result.Get(xorstr("endtime").crypt_get(), endtime);
					����ʱ��� = StringToDatetime(endtime);
					endtime = aes_256_cbc_encode(endtime, �����ִ�����key);
					return true;
				}
				else
				{
					LastErroMsg = aes_256_cbc_encode(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = aes_256_cbc_encode(xorstr("����ʧ�ܣ�").crypt_get(), �����ִ�����key);
				return false;
			}
			return false;
		}
		//�ǳ�
		bool LogOut()
		{
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = xorstr("action").crypt_get();
			api.Value = xorstr("logout").crypt_get();
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = xorstr("user").crypt_get();
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);

			//����
			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(xorstr("code").crypt_get(), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					return true;
				}
				else
				{
					LastErroMsg = aes_256_cbc_encode(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = aes_256_cbc_encode(xorstr("����ʧ�ܣ�").crypt_get(), �����ִ�����key);
				return false;
			}
			return false;
		}

	private:
		std::string �ͻ�����Կ;
		char �ͻ���IV����[8] = { 0 };
		std::string �������Կ;
		char �����IV����[8] = { 0 };
		std::string �����ִ�����key;
	private:
		//ͨѶ��Կ
		std::string Key;
		//���sid
		std::string Sid;
		//ʱ���
		std::string Time;
		//��ʱ���token(sid+key+t ƴ�Ӻ�ȡMD5ֵ)
		std::string Md5_1;
		//��ǰ����MD5ֵ,�������У��MD5,���ֵ����,���ڳ�������ʱ��̬��ȡ����MD5ֵ.
		std::string Md5_2;
		//moduleMd5,������Ȩ����
		std::string Md5_3;
		//������
		std::string Mac_code;
		//�ͻ���id������ʶ��ͻ��ˣ���ֹͬʱ�����¼
		std::string ClientId;
		//ͨ����Կ(webKey),������Ȩ����.
		std::string WebKey;

		//�ͻ���signƴ�ӹ���
		std::string SignRuleClient;
		//�����signƴ�ӹ���
		std::string SignRuleServer;
		//��������ַ
		std::string Domain;
		//����ҳ
		std::string PageAddr;
		//�������˿�
		WORD Port;





	private:
		//�������󲢷�������
		BOOL HttpRequest(std::vector<NETWORK::Info>& Variable, neb::CJsonObject& RetJson_)
		{
			/*�������*/
			std::string uuid = this->generate();
			int Time = time(NULL);
			std::string timeStr = std::to_string(Time);
			neb::CJsonObject json;
			//�̶�����
			json.Add(xorstr("sid").crypt_get(), this->Sid);
			json.Add(xorstr("uuid").crypt_get(), uuid);
			json.Add(xorstr("t").crypt_get(), Time);
			json.Add(xorstr("m1").crypt_get(), MD5(this->Sid + this->Key + timeStr).toString());
			json.Add(xorstr("m2").crypt_get(), this->Md5_2);
			json.Add(xorstr("m3").crypt_get(), this->Md5_3);
			json.Add(xorstr("mcode").crypt_get(), this->Mac_code);
			json.Add(xorstr("clientid").crypt_get(), this->ClientId);
			json.Add(xorstr("webkey").crypt_get(), this->WebKey);
			//�ɱ����
			for (size_t i = 0; i < Variable.size(); i++)
			{
				json.Add(Variable[i].Key, Variable[i].Value);
			}
			/*std::cout << "�������ģ�" << json.ToString() << std::endl;
			std::cout << std::endl;*/
			//������
			//תΪUTF8����
			std::string UTF8_Str = this->string_To_UTF8(json.ToString());
			//����DES����
			std::string DES���� = this->des_cbc_encrypt(UTF8_Str, this->�ͻ�����Կ);
			//����base64����
			std::string base���� = base64_encode((unsigned char const*)DES����.c_str(), DES����.length());

			//����signƴ��
			std::string signƴ�� = this->SignRuleClient;
			signƴ�� = this->replace_all(signƴ��, xorstr("[data]").crypt_get(), base����);
			signƴ�� = this->replace_all(signƴ��, xorstr("[key]").crypt_get(), this->Key);
			std::string signֵ = MD5(signƴ��).toString();

			//����url���룬��ֹ��������ж�ʧ�����ַ�
			UrlEncoder url;
			std::string url���� = url.Encode(base����, false);

			//���з�� 
			std::string ���� = xorstr("data=").crypt_get() + url���� + xorstr("&sign=").crypt_get() + signֵ;
			/*std::cout << "�������ģ�" << ���� << std::endl;
			std::cout << std::endl;*/
			//���ͷ��
			std::string �������� = this->GetWeb(this->Domain, this->Port, this->PageAddr, NETWORK::LAINSPATTERN::POST, ����);
			/*std::cout << "�������ģ�" << �������� << std::endl;
			std::cout <<  std::endl;*/

			/*�����֤*/

			//ȡ��������sign
			neb::CJsonObject RetJson(��������);
			std::string RetData;
			std::string RetSign;
			RetJson.Get(xorstr("data").crypt_get(), RetData);
			RetJson.Get(xorstr("sign").crypt_get(), RetSign);
			//url����
			UrlEncoder RetUrl;
			std::string url����;
			RetUrl.Decode(RetData, &url����);
			//����signƴ��
			std::string Retsignƴ�� = this->SignRuleServer;
			Retsignƴ�� = this->replace_all(Retsignƴ��, xorstr("[data]").crypt_get(), url����);
			Retsignƴ�� = this->replace_all(Retsignƴ��, xorstr("[key]").crypt_get(), this->Key);
			std::string Retsignֵ = MD5(Retsignƴ��).toString();

			//У�����Ϸ���   1�Ա�signֵ�Ƿ���ȷ��2�Աȷ��uuid�Ƿ���ȷ��3�Աȷ��ʱ���Ƿ����̫����

			//�Ա�signֵ
			if (Retsignֵ != RetSign)
			{
				return false;
			}
			//��������
			std::string base���� = base64_decode(url����);
			//DES����
			std::string ���ؽ������� = this->UTF8_To_string(this->des_cbc_decrypt(base����, this->�������Կ));
			//json����
			/*std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "���ص�json���ģ�" << ���ؽ������� << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;*/
			//std::string retstring = UnEscapeUTF8((char*)���ؽ�������.c_str());

			//�������������UTF8ת��������jsonת������Ϊ�˽������bug����ѧ��
			RetJson_ = (this->UTF8_To_string(neb::CJsonObject(���ؽ�������).ToString()));


			std::string uuid_new;
			RetJson_.Get(xorstr("uuid").crypt_get(), uuid_new);
			int time_new = 0;
			RetJson_.Get(xorstr("t").crypt_get(), time_new);
			this->��ǰ����ʱ��� = time_new;
			if (!(uuid_new == uuid && abs(time_new - time(NULL)) < 10))
			{
				return false;
			}

			return true;
		}

		//�滻�ִ�
		std::string& replace_all(std::string& str, const   std::string& old_value, const   std::string& new_value)
		{
			while (true) {
				std::string::size_type   pos(0);
				if ((pos = str.find(old_value)) != std::string::npos)
					str.replace(pos, old_value.length(), new_value);
				else   break;
			}
			return   str;
		}
		//�ִ�ת��
		std::string UTF8_To_string(const std::string& str)
		{
			int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
			wchar_t* pwBuf = new wchar_t[nwLen + 1];    //һ��Ҫ��1����Ȼ�����β�� 
			memset(pwBuf, 0, nwLen * 2 + 2);
			MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);
			int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
			char* pBuf = new char[nLen + 1];
			memset(pBuf, 0, nLen + 1);
			WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

			std::string strRet = pBuf;

			delete[]pBuf;
			delete[]pwBuf;
			pBuf = NULL;
			pwBuf = NULL;

			return strRet;
		}
		std::string UTF8_To_string(char* szCode)
		{
			string strRet = "";
			for (int i = 0; i < 4; i++)
			{
				if (szCode[i] >= '0' && szCode[i] <= '9')	continue;
				if (szCode[i] >= 'A' && szCode[i] <= 'F')	continue;
				if (szCode[i] >= 'a' && szCode[i] <= 'f')	continue;
				return strRet;
			}

			char unicode_hex[5] = { 0 };
			memcpy(unicode_hex, szCode, 4);
			unsigned int iCode = 0;
			sscanf_s(unicode_hex, "%04x", &iCode);
			wchar_t wchChar[4] = { 0 };
			wchChar[0] = iCode;

			char szAnsi[8] = { 0 };
			WideCharToMultiByte(CP_ACP, NULL, wchChar, 1, szAnsi, sizeof(szAnsi), NULL, NULL);
			strRet = string(szAnsi);

			return strRet;

		}
		//�ִ�ת��
		std::string string_To_UTF8(const std::string& str)
		{
			int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
			wchar_t* pwBuf = new wchar_t[nwLen + 1];    //һ��Ҫ��1����Ȼ�����β�� 
			ZeroMemory(pwBuf, nwLen * 2 + 2);
			::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
			int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
			char* pBuf = new char[nLen + 1];
			ZeroMemory(pBuf, nLen + 1);
			::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

			std::string strRet(pBuf);

			delete[]pwBuf;
			delete[]pBuf;
			pwBuf = NULL;
			pBuf = NULL;

			return strRet;
		}
		//����http����
		std::string GetWeb(std::string Domain, WORD Port, std::string PageAddr, DWORD Pattern, std::string PostBuff)
		{
			HINTERNET hInternet, hConnect, hRequest;
			DWORD len = 0;
			std::string WebRet;
			char useragent[] = "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.1)";
			std::string headers = "Accept: */*\n\rAccept-Language: zh-cn\n\rContent-Type: application/x-www-form-urlencoded\n\r";
			headers = headers + "Referer: " + Domain + PageAddr;
			std::string sPattern;
			if (Pattern == 1)
				sPattern = "POST";
			else
				sPattern = "GET";
			hInternet = InternetOpenA(useragent, 1, NULL, NULL, NULL);
			if (hInternet)
			{
				hConnect = InternetConnectA(hInternet, Domain.c_str(), Port, NULL, NULL, 3, NULL, NULL);
				if (hConnect)
				{
					hRequest = HttpOpenRequestA(hConnect, sPattern.c_str(), PageAddr.c_str(), "HTTP/1.1", NULL, NULL, (INTERNET_FLAG_RELOAD && INTERNET_COOKIE_THIRD_PARTY && INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS), 0);
					if (hRequest)
					{
						HttpSendRequestA(hRequest, headers.c_str(), headers.length(), (LPVOID)(PostBuff.c_str()), PostBuff.length());
						char* Temp = new char[4096];
						while (true)
						{
							memset(Temp, 0, 4096);
							InternetReadFile(hRequest, Temp, 4096, &len);
							WebRet = WebRet + Temp;
							if (len == 0)
							{
								delete[] Temp;
								break;
							}
						}
						InternetCloseHandle(hRequest);
					}
					InternetCloseHandle(hConnect);
				}
				InternetCloseHandle(hInternet);
			}
			return WebRet;
		}
		//des cbcģʽ�������ģʽnopadding
		std::string des_cbc_encrypt(const std::string& Text, const std::string& key)
		{
			std::string strCipherText;
			DES_cblock keyEncrypt, ivec;
			memset(keyEncrypt, 0, 8);
			if (key.length() <= 8)
				memcpy(keyEncrypt, key.c_str(), key.length());
			else
				memcpy(keyEncrypt, key.c_str(), 8);
			DES_key_schedule keySchedule;  //��Կ��
			DES_set_key_unchecked(&keyEncrypt, &keySchedule);   //������Կ���Ҳ������Կ��ż��  
			memcpy(ivec, �ͻ���IV����, sizeof(�ͻ���IV����));
			// ѭ�����ܣ�ÿ8�ֽ�һ��    
			const_DES_cblock inputText;
			unsigned char outputText[9];
			std::vector<unsigned char> vecCiphertext;
			unsigned char tmp[8];
			string clearText = Text;

			while (clearText.length() % 8 != 0)
			{
				clearText += ' ';
			}
			char sp[100] = { '\0' };
			memset(sp, ' ', 99);
			clearText += sp;
			for (int i = 0; i < clearText.length() / 8; i++)
			{
				memcpy(inputText, clearText.c_str() + i * 8, 8);
				DES_ncbc_encrypt(inputText, outputText, 8, &keySchedule, &ivec, DES_ENCRYPT);  //����
				memcpy(tmp, outputText, 8);

				for (int j = 0; j < 8; j++)
					vecCiphertext.push_back(tmp[j]);

				//����ivec
				memcpy(ivec, outputText, 8);
			}

			strCipherText.clear();
			strCipherText.assign(vecCiphertext.begin(), vecCiphertext.end());
			return strCipherText;
		}
		//���� cbc 
		std::string des_cbc_decrypt(const std::string& cipherText, const std::string& key)
		{
			//static unsigned char cbc_iv[8] = { 'w', '6', 'n', 'E', 'w', 'U', '3', 't' };//vPVaKkC3  w6nEwU3t
			//��ʼ��IV���� 
			std::string clearText;
			DES_cblock keyEncrypt, ivec;
			memset(keyEncrypt, 0, 8);

			if (key.length() <= 8)
				memcpy(keyEncrypt, key.c_str(), key.length());
			else
				memcpy(keyEncrypt, key.c_str(), 8);

			DES_key_schedule keySchedule;  //��Կ��
			DES_set_key_unchecked(&keyEncrypt, &keySchedule);   //������Կ���Ҳ������Կ��ż��  

			memcpy(ivec, �����IV����, sizeof(�����IV����));

			// ѭ�����ܣ�ÿ8�ֽ�һ��    
			const_DES_cblock inputText;
			DES_cblock outputText;
			std::vector<unsigned char> vecCleartext;
			unsigned char tmp[8];

			for (int i = 0; i < cipherText.length() / 8; i++)
			{
				memcpy(inputText, cipherText.c_str() + i * 8, 8);
				DES_ncbc_encrypt(inputText, outputText, 8, &keySchedule, &ivec, DES_DECRYPT);  //����
				memcpy(tmp, outputText, 8);

				for (int j = 0; j < 8; j++)
					vecCleartext.push_back(tmp[j]);

				//����ivec
				//memcpy(ivec, outputText, 8);  //���ܹ��̲���Ҫ��ǰһ��Ľ����Ϊ��һ���IV
			}

			if (clearText.length() % 8 != 0)
			{
				int tmp1 = clearText.length() / 8 * 8;
				int tmp2 = clearText.length() - tmp1;
				memset(inputText, ' ', tmp2);
				memcpy(inputText, cipherText.c_str() + tmp1, tmp2);
				DES_ncbc_encrypt(inputText, outputText, tmp2, &keySchedule, &ivec, DES_DECRYPT);  //����
				memcpy(tmp, outputText, tmp2);
				for (int j = 0; j < 8; j++)
					vecCleartext.push_back(tmp[j]);
			}

			clearText.clear();
			clearText.assign(vecCleartext.begin(), vecCleartext.end());
			return clearText;
		}
		//AES����
		std::string aes_256_cbc_encode(const std::string& data, const std::string& password)
		{
			// ����Ĭ�Ͻ�ivȫ��Ϊ�ַ�0
			unsigned char iv[AES_BLOCK_SIZE] = { '0','0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };

			AES_KEY aes_key;
			if (AES_set_encrypt_key((const unsigned char*)password.c_str(), password.length() * 8, &aes_key) < 0)
			{
				//assert(false);
				return "";
			}
			std::string strRet;
			std::string data_bak = data;
			unsigned int data_length = data_bak.length();

			// ZeroPadding
			int padding = 0;
			if (data_bak.length() % (AES_BLOCK_SIZE) > 0)
			{
				padding = AES_BLOCK_SIZE - data_bak.length() % (AES_BLOCK_SIZE);
			}
			// ��һЩ���ʵ���У���ʹ��16�ı���Ҳ������16���ȵĲ���
			/*else
			{
				padding = AES_BLOCK_SIZE;
			}*/

			data_length += padding;
			while (padding > 0)
			{
				data_bak += '\0';
				padding--;
			}

			for (unsigned int i = 0; i < data_length / (AES_BLOCK_SIZE); i++)
			{
				std::string str16 = data_bak.substr(i * AES_BLOCK_SIZE, AES_BLOCK_SIZE);
				unsigned char out[AES_BLOCK_SIZE];
				::memset(out, 0, AES_BLOCK_SIZE);
				AES_cbc_encrypt((const unsigned char*)str16.c_str(), out, AES_BLOCK_SIZE, &aes_key, iv, AES_ENCRYPT);
				strRet += std::string((const char*)out, AES_BLOCK_SIZE);
			}

			return base64_encode((unsigned char const*)strRet.c_str(), strRet.length());
		}
		//AES����
		std::string aes_256_cbc_decode(const std::string& strData,const std::string& password)
		{
			std::string str_decode_base64 = base64_decode(strData);
			// ����Ĭ�Ͻ�ivȫ��Ϊ�ַ�0
			unsigned char iv[AES_BLOCK_SIZE] = { '0','0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };

			AES_KEY aes_key;
			if (AES_set_decrypt_key((const unsigned char*)password.c_str(), password.length() * 8, &aes_key) < 0)
			{
				//assert(false);
				return "";
			}
			std::string strRet;
			for (unsigned int i = 0; i < str_decode_base64.length() / AES_BLOCK_SIZE; i++)
			{
				std::string str16 = str_decode_base64.substr(i * AES_BLOCK_SIZE, AES_BLOCK_SIZE);
				unsigned char out[AES_BLOCK_SIZE];
				::memset(out, 0, AES_BLOCK_SIZE);
				AES_cbc_encrypt((const unsigned char*)str16.c_str(), out, AES_BLOCK_SIZE, &aes_key, iv, AES_DECRYPT);
				strRet += std::string((const char*)out, AES_BLOCK_SIZE);
			}
			return strRet;
		}
		//Guid(ȫ��Ψһʶ����)���ɷ���
		std::string generate()
		{
			char buf[GUID_LEN] = { 0 };
			GUID guid;

			if (CoCreateGuid(&guid))
			{
				return std::move(std::string(""));
			}

			sprintf(buf,
				"%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X",
				guid.Data1, guid.Data2, guid.Data3,
				guid.Data4[0], guid.Data4[1], guid.Data4[2],
				guid.Data4[3], guid.Data4[4], guid.Data4[5],
				guid.Data4[6], guid.Data4[7]);

			return std::move(std::string(buf));
		}
		//��ȡ����ַ���
		std::unique_ptr<char[]> _GetRandStr(IN int SIZE_CHAR)
		{

			//char* result = applyBuffer(SIZE_CHAR + 1);

			static const char CCH[] = "_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";

			std::unique_ptr<char[]> result(new char[SIZE_CHAR + 1]());

			int cchLen = sizeof(CCH);

			srand((unsigned)time(NULL));

			for (int i = 0; i < SIZE_CHAR; ++i)
			{

				//int x = rand() % (sizeof(CCH) - 1); //�����������, ��Ϊ���������������ĵ�λ���ز������,
				//RAND MAX ��ANSI ��#define ��<stdlib.h>
				//RAND MAX �Ǹ�����, ��������C �⺯��rand() �Ĺ̶���Χ��
				//��������RAND MAX Ϊ������ֵ, Ҳû�а취Ҫ��rand() ����������Χ��ֵ��

				int x = rand() / (RAND_MAX / (cchLen - 1));
				result[i] = CCH[x];
			}

			return result;
		}

		//��ʽ�����ʱ���������Ĳ����Ǿ�ȷ��
		std::string DatetimeToString(time_t time, bool day_, bool hour_, bool minute_, bool second_)
		{
			tm* tm_ = localtime(&time);                // ��time_t��ʽת��Ϊtm�ṹ��
			int year, month, day, hour, minute, second;// ����ʱ��ĸ���int��ʱ������
			year = tm_->tm_year + 1900;                // ��ʱ�������꣬����tm�ṹ��洢���Ǵ�1900�꿪ʼ��ʱ�䣬������ʱ����intΪtm_year����1900��
			month = tm_->tm_mon + 1;                   // ��ʱ�������£�����tm�ṹ����·ݴ洢��ΧΪ0-11��������ʱ����intΪtm_mon����1��
			day = tm_->tm_mday;                        // ��ʱ�������ա�
			hour = tm_->tm_hour;                       // ��ʱ������ʱ��
			minute = tm_->tm_min;                      // ��ʱ�������֡�
			second = tm_->tm_sec;                      // ��ʱ�������롣
			char yearStr[5], monthStr[3], dayStr[3], hourStr[3], minuteStr[3], secondStr[3];// ����ʱ��ĸ���char*������
			sprintf(yearStr, "%d", year);              // �ꡣ
			sprintf(monthStr, "%d", month);            // �¡�
			sprintf(dayStr, "%d", day);                // �ա�
			sprintf(hourStr, "%d", hour);              // ʱ��
			sprintf(minuteStr, "%d", minute);          // �֡�
			if (minuteStr[1] == '\0')                  // �����Ϊһλ����5������Ҫת���ַ���Ϊ��λ����05��
			{
				minuteStr[2] = '\0';
				minuteStr[1] = minuteStr[0];
				minuteStr[0] = '0';
			}
			sprintf(secondStr, "%d", second);          // �롣
			if (secondStr[1] == '\0')                  // �����Ϊһλ����5������Ҫת���ַ���Ϊ��λ����05��
			{
				secondStr[2] = '\0';
				secondStr[1] = secondStr[0];
				secondStr[0] = '0';
			}

			if (day_)
			{
				return(std::string(yearStr) + "��" + std::string(monthStr) + "��" + std::string(dayStr) + "��");
			}
			else if (hour_)
			{
				return(std::string(yearStr) + "��" + std::string(monthStr) + "��" + std::string(dayStr) + "��" + std::string(hourStr) + "ʱ");
			}
			else if (minute_)
			{
				return(std::string(yearStr) + "��" + std::string(monthStr) + "��" + std::string(dayStr) + "��" + std::string(hourStr) + "ʱ" + std::string(minuteStr) + "��");
			}
			else if (second_)
			{
				return(std::string(yearStr) + "��" + std::string(monthStr) + "��" + std::string(dayStr) + "��" + std::string(hourStr) + "ʱ" + std::string(minuteStr) + "��" + std::string(secondStr) + "��");
			}
			else
			{
				return(std::string(yearStr) + "��" + std::string(monthStr) + "��" + std::string(dayStr) + "��" + std::string(hourStr) + "ʱ" + std::string(minuteStr) + "��" + std::string(secondStr) + "��");
			}

		}
		time_t StringToDatetime(std::string str)
		{
			char* cha = (char*)str.data();             // ��stringת����char*��
			tm tm_;                                    // ����tm�ṹ�塣
			int year, month, day, hour, minute, second;// ����ʱ��ĸ���int��ʱ������
			sscanf(cha, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);// ��string�洢������ʱ�䣬ת��Ϊint��ʱ������
			tm_.tm_year = year - 1900;                 // �꣬����tm�ṹ��洢���Ǵ�1900�꿪ʼ��ʱ�䣬����tm_yearΪint��ʱ������ȥ1900��
			tm_.tm_mon = month - 1;                    // �£�����tm�ṹ����·ݴ洢��ΧΪ0-11������tm_monΪint��ʱ������ȥ1��
			tm_.tm_mday = day;                         // �ա�
			tm_.tm_hour = hour;                        // ʱ��
			tm_.tm_min = minute;                       // �֡�
			tm_.tm_sec = second;                       // �롣
			tm_.tm_isdst = 0;                          // ������ʱ��
			time_t t_ = mktime(&tm_);                  // ��tm�ṹ��ת����time_t��ʽ��
			return t_;                                 // ����ֵ��
		}


		private:

			static std::map<size_t, std::string> ErroMap;
			std::string GetMessageWithErroCode(size_t code)
			{
				std::map<size_t, std::string>::iterator iter;
				iter = ErroMap.find(code);
				if (iter != ErroMap.end())
				{
					return iter->second;
				}
				else
				{
					return "������벻��";
				}
			}



	};

	std::map<size_t, std::string> CHwdNetWork::ErroMap =
	{
		{ 201 , xorstr("���������").crypt_get()},
		{ 202 , xorstr("ͨ����ԿУ��ʧ��").crypt_get()},
		{ 203 , xorstr("���MD5У��ʧ��").crypt_get()},
		{ 206 , xorstr("�˺Ż��������").crypt_get()},
		{ 207 , xorstr("��ֵ��������").crypt_get()},
		{ 209 , xorstr("��ǰ��������󶨻�������").crypt_get()},
		{ 210 , xorstr("�����˻��ѹ���,���ֵ���¼").crypt_get()},
		{ 211 , xorstr("�����˻�����Ϊ0,���ֵ���¼").crypt_get()},
		{ 212 , xorstr("���ά��").crypt_get()},
		{ 213 , xorstr("ͨ��֤����ͣ,��ֹ��¼").crypt_get()},
		{ 214 , xorstr("�����˻��ѹ���,�޷�ת��,ʹ�ñ�����ֵ���Զ���������").crypt_get()},
		{ 215 , xorstr("����ʣ��ʱ�䲻����֧��ת��۳�ʱ��,���ֵ.ʹ�ñ�����ֵ���Զ���������").crypt_get()},
		{ 216 , xorstr("ת��ʧ��,δ֪ԭ��,����ϵ�ͷ�����").crypt_get()},
		{ 217 , xorstr("�����˻�����Ϊ0,�޷�ת��,ʹ�ñ�����ֵ���Զ���������").crypt_get()},
		{ 218 , xorstr("����ʣ�����������֧��ת��۳�����,���ֵ.ʹ�ñ�����ֵ���Զ���������").crypt_get()},
		{ 219 , xorstr("��ֵ�˺Ų�����").crypt_get()},
		{ 220 , xorstr("��ֵ��������").crypt_get()},
		{ 221 , xorstr("��ֵ����Ŀ������,����ϵ�ͷ�").crypt_get()},
		{ 222 , xorstr("���ĳ�ֵ���뵱ǰ�˺����Ͳ���,�뵽�ں��ٳ�ֵ").crypt_get()},
		{ 223 , xorstr("���ĳ�ֵ���뵱ǰ�˺����Ͳ���,�뽫����������ٳ�ֵ").crypt_get()},
		{ 224 , xorstr("�۵��˻�������").crypt_get()},
		{ 225 , xorstr("��������,�۵�ʧ��").crypt_get()},
		{ 226 , xorstr("�۵�ʧ��,δ֪ԭ��,����ϵ�ͷ�").crypt_get()},
		{ 227 , xorstr("�˻�����ͣ,��ֹ��¼").crypt_get()},
		{ 228 , xorstr("ͨ��֤��ɾ��,��������").crypt_get()},
		{ 229 , xorstr("ͨ��֤�ѱ���ͣ,��������").crypt_get()},
		{ 230 , xorstr("����˻��ѱ�ɾ��,��������").crypt_get()},
		{ 231 , xorstr("����˻��ѱ���ͣ,��������").crypt_get()},
		{ 232 , xorstr("���ĵ���Ϊ0,��������").crypt_get()},
		{ 233 , xorstr("�����˻��ѵ���,��������").crypt_get()},
		{ 234 , xorstr("�����˻�������,�����ر�.").crypt_get()},
		{ 235 , xorstr("���¼���").crypt_get()},
		{ 236 , xorstr("�û����ϰ�ʧ��,δ֪ԭ��").crypt_get()},
		{ 237 , xorstr("��ʱ�˻�������").crypt_get()},
		{ 238 , xorstr("ʱ�䲻��,��ʱʧ��").crypt_get()},
		{ 239 , xorstr("��ʱʧ��,δ֪ԭ��,����ϵ�ͷ�").crypt_get()},
		{ 240 , xorstr("�����˺�����������,���Ժ�����,���쳣�˳�,��ȴ������Ӻ����µ�¼").crypt_get()},
		{ 241 , xorstr("��ֹת��").crypt_get()},
		{ 242 , xorstr("�Ƽ��˲�����").crypt_get()},
		{ 243 , xorstr("�û���Ϊ3-12λ,֧������").crypt_get()},
		{ 244 , xorstr("����Ϊ6-16λ").crypt_get()},
		{ 245 , xorstr("�û����Ѵ���,�����!").crypt_get()},
		{ 246 , xorstr("�����ѱ�ʹ��,�����!").crypt_get()},
		{ 247 , xorstr("ע��ʧ��,δ֪ԭ��.").crypt_get()},
		{ 248 , xorstr("�û������ڻ��ѱ���ͣ").crypt_get()},
		{ 249 , xorstr("�ʼ�����ʧ��,����ϵ�ͷ�����.").crypt_get()},
		{ 250 , xorstr("�ʼ���֤�����").crypt_get()},
		{ 251 , xorstr("�����޸�ʧ��,����ϵ�ͷ�����").crypt_get()},
		{ 252 , xorstr("��ʧ��,���󶨵�����û�������").crypt_get()},
		{ 253 , xorstr("�˻�δ��¼,���Զ���PHP����������").crypt_get()},
		{ 500 , xorstr("���ID����").crypt_get()},
		{ 601 , xorstr("����ʱ������������̫��,ͨ��ʧ��").crypt_get()},
		{ 602 , xorstr("�����ظ��ύ").crypt_get()},
	};

}