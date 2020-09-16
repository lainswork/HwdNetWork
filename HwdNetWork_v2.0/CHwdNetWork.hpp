


#pragma once
//http�⣬�������������ǰ�棬������windows.h��ͻ 
#include "http/httplib.h"

//AES�����㷨
#include "aes/aes.hpp"

//���ܾ�̬�ִ�
#include"tool/XorStr.hpp"

//md5������
#include "tool/md5.hpp"

//url�������
#include "tool/UrlEncoder.hpp"

//������ͷ�ļ�
#include "tool/HardWare.hpp"

//json����
#include "json/CJsonObject.hpp"

//�ַ���ת��
#include "tool/EncodingConversion.hpp"


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
			return decode_str(LastErroMsg, this->�����ִ�����key);
		}
		//����
		std::string GetNotice()
		{
			return decode_str(notice, this->�����ִ�����key);
		}
		//�������
		std::string GetName()
		{
			return decode_str(name, this->�����ִ�����key);
		}
		//�汾��
		std::string GetVersion()
		{
			return decode_str(version, this->�����ִ�����key);
		}
		//�ͷ�QQ
		std::string GetQq()
		{
			return decode_str(qq, this->�����ִ�����key);
		}
		//���������ַ
		std::string GetDownloadurl()
		{
			return decode_str(downloadurl, this->�����ִ�����key);
		}
		//���������ַ
		std::string GetUpdateurl()
		{
			return decode_str(updateurl, this->�����ִ�����key);
		}
		//�û�������,������Ϸ�ŵ�
		std::string Getbind()
		{
			return decode_str(bind, this->�����ִ�����key);
		}
		//����ʱ��
		std::string GetEndtime()
		{
			return decode_str(endtime, this->�����ִ�����key);
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
			return decode_str(point, this->�����ִ�����key);
		}
		//�������
		size_t GetPoint_size_t()
		{
			return �������;
		}
		//�û��Զ��峣��
		std::string GetPara()
		{
			return decode_str(para, this->�����ִ�����key);
		}
		//����Զ��峣��
		std::string GetSoftpara()
		{
			return decode_str(softpara, this->�����ִ�����key);
		}
		//�û���
		std::string GetUser()
		{
			return decode_str(user, this->�����ִ�����key);
		}
		//����
		std::string GetPass()
		{
			return decode_str(pass, this->�����ִ�����key);
		}
		//�˻����
		std::string GetBalance()
		{
			return decode_str(balance, this->�����ִ�����key);
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
			IN std::string _SignRuleServer/*�����sign����*/,
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
			info.Key = XorStr("action") ;
			info.Value = XorStr("init") ;
			std::vector<Info> test;
			test.push_back(info);

			neb::CJsonObject retJson;
			if (HttpRequest(test, retJson))
			{
				std::string codestr;
				retJson.Get(XorStr("code"), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(XorStr("result") , result);

					result.Get(XorStr("notice") , this->notice);
					result.Get(XorStr("name") , this->name);
					result.Get(XorStr("version") , this->version);
					result.Get(XorStr("qq") , this->qq);
					result.Get(XorStr("downloadurl") , this->downloadurl);
					result.Get(XorStr("updateurl") , this->updateurl);


					this->notice = replace_all(this->notice, "<p>", " ");
					this->notice = replace_all(this->notice, "</p>", " ");
					this->notice = STR_EC::UTF8ToGBK(this->notice);
					this->notice = encode_str(notice, �����ִ�����key);
					this->name = encode_str(name, �����ִ�����key);
					this->version = encode_str(version, �����ִ�����key);
					this->qq = encode_str(qq, �����ִ�����key);
					this->downloadurl = encode_str(downloadurl, �����ִ�����key);
					this->updateurl = encode_str(updateurl, �����ִ�����key);

					return true;
				}
				else
				{
					LastErroMsg = encode_str(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = encode_str(XorStr("����ʧ�ܣ�") , �����ִ�����key);
				return false;
			}

		}



		//�û���¼
		bool UserLogin(IN std::string username/*�û���*/, IN std::string password/*����*/)
		{
			//action=login&user=�û���&pwd=����&code=��֤��
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = XorStr("action") ;
			api.Value = XorStr("login") ;
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = XorStr("user") ;
			Var1.Value = username;
			PostMsgInfo.push_back(Var1);
			Info Var2;
			Var2.Key = XorStr("pwd") ;
			Var2.Value = password;
			PostMsgInfo.push_back(Var2);

			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(XorStr("code"), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(XorStr("result") , result);
					result.Get(XorStr("bind") , bind);
					result.Get(XorStr("endtime") , endtime);
					����ʱ��� = StringToDatetime(endtime);
					result.Get(XorStr("para") , para);
					result.Get(XorStr("point") , point);
					������� = atoi(point.c_str());
					result.Get(XorStr("softpara") , softpara);
					result.Get(XorStr("user") , user);
					
					this->bind = encode_str(this->bind, �����ִ�����key);
					this->endtime = encode_str(this->endtime, �����ִ�����key);
					this->para = encode_str(this->para, �����ִ�����key);
					this->point = encode_str(this->point, �����ִ�����key);
					this->softpara = encode_str(this->softpara, �����ִ�����key);
					this->user = encode_str(this->user, �����ִ�����key);
					pass = password;
					this->pass = encode_str(password, �����ִ�����key);
					return true;
				}
				else
				{
					LastErroMsg = encode_str(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = encode_str(XorStr("����ʧ�ܣ�") , �����ִ�����key);
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
			api.Key = XorStr("action") ;
			api.Value = XorStr("heartbeat") ;
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = XorStr("user") ;
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);


			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(XorStr("code"), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(XorStr("result") , result);

					result.Get(XorStr("bind") , bind);
					result.Get(XorStr("endtime") , endtime);
					����ʱ��� = StringToDatetime(endtime);
					result.Get(XorStr("para") , para);
					result.Get(XorStr("point") , point);
					������� = atoi(point.c_str());
					result.Get(XorStr("softpara") , softpara);

					bind = encode_str(bind, �����ִ�����key);
					endtime = encode_str(endtime, �����ִ�����key);
					para = encode_str(para, �����ִ�����key);
					point = encode_str(point, �����ִ�����key);
					softpara = encode_str(softpara, �����ִ�����key);


					return true;
				}
				else
				{

					LastErroMsg = encode_str(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = encode_str(XorStr("����ʧ�ܣ�") , �����ִ�����key);
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
			api.Key = XorStr("action") ;
			api.Value = XorStr("bindstr") ;
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = XorStr("user") ;
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);
			Info Var2;
			Var2.Key = XorStr("pwd") ;
			Var2.Value = this->GetPass();
			PostMsgInfo.push_back(Var2);
			Info Var3;
			Var3.Key = XorStr("str") ;
			Var3.Value = str;
			PostMsgInfo.push_back(Var3);


			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(XorStr("code"), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					return true;
				}
				else
				{
					LastErroMsg = encode_str(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = encode_str(XorStr("����ʧ�ܣ�") , �����ִ�����key);
				return false;
			}
			return false;
		}
		//�󶨻�����
		bool BindMac(IN std::string username/*�û���*/)
		{
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = XorStr("action") ;
			api.Value = XorStr("bind") ;
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = XorStr("user") ;
			Var1.Value = username;
			PostMsgInfo.push_back(Var1);


			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(XorStr("code"), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					return true;
				}
				else
				{
					LastErroMsg = encode_str(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = encode_str(XorStr("����ʧ�ܣ�") , �����ִ�����key);
				return false;
			}
			return false;
		}
		//��ֵ
		bool RechArge(IN std::string username/*�û���*/, IN std::string cdkey/*��ֵ��*/)
		{
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = XorStr("action") ;
			api.Value = XorStr("recharge") ;
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = XorStr("user") ;
			Var1.Value = username;
			PostMsgInfo.push_back(Var1);
			Info Var2;
			Var2.Key = XorStr("card") ;
			Var2.Value = cdkey;
			PostMsgInfo.push_back(Var2);


			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(XorStr("code"), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(XorStr("result") , result);

					result.Get(XorStr("balance") , balance);
					result.Get(XorStr("endtime") , endtime);
					����ʱ��� = StringToDatetime(endtime);
					result.Get(XorStr("point") , point);
					������� = atoi(point.c_str());

					balance = encode_str(balance, �����ִ�����key);
					endtime = encode_str(endtime, �����ִ�����key);
					point = encode_str(point, �����ִ�����key);

					balance = encode_str(balance, �����ִ�����key);
					endtime = encode_str(endtime, �����ִ�����key);
					point = encode_str(point, �����ִ�����key);

					return true;
				}
				else
				{
					LastErroMsg = encode_str(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = encode_str(XorStr("����ʧ�ܣ�") , �����ִ�����key);
				return false;
			}
			return false;
		}
		//�۵�
		bool DeductPoint(IN std::string number/*�۳�����*/, IN DEDUCTPOINTMODE mode/*�۵㷽ʽ*/)
		{
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = XorStr("action") ;
			api.Value = XorStr("deductpoint") ;
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = XorStr("user") ;
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);
			Info Var2;
			Var2.Key = XorStr("num") ;
			Var2.Value = number;
			PostMsgInfo.push_back(Var2);

			Info Var3;
			if (mode == DEDUCTPOINTMODE::ONEDAY_ONCE)
			{

				Var3.Key = XorStr("filter") ;
				Var3.Value = XorStr("1") ;
				PostMsgInfo.push_back(Var3);
				Info Var4;
				Var4.Key = XorStr("msg") ;
				time_t today = time(NULL);
				Var4.Value = Mac_code + (DatetimeToString(today, true, false, false, false));
				
				PostMsgInfo.push_back(Var4);
			}
			else
			{
				Var3.Key = XorStr("filter") ;
				Var3.Value = XorStr("0") ;
				PostMsgInfo.push_back(Var3);
			}

			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(XorStr("code"), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(XorStr("result"), result);
					result.Get(XorStr("point"), point);
					������� = atoi(point.c_str());
					point = encode_str(point, �����ִ�����key);

					return true;
				}
				else
				{

					LastErroMsg = encode_str(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = encode_str(XorStr("����ʧ�ܣ�") , �����ִ�����key);
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
			api.Key = XorStr("action") ;
			api.Value = XorStr("deducttime") ;
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = XorStr("user") ;
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);
			Info Var3;
			Var3.Key = XorStr("num") ;
			Var3.Value = number;
			PostMsgInfo.push_back(Var3);
			Info Var4;
			Var4.Key = XorStr("msg") ;
			Var4.Value = XorStr("DeductTime:")  + DatetimeToString(time(NULL), true, true, true, false);
			PostMsgInfo.push_back(Var4);
			Info Var5;
			Var5.Key = XorStr("filter") ;
			Var5.Value = XorStr("0") ;
			PostMsgInfo.push_back(Var5);
			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{

				
				std::string codestr;
				retJson.Get(XorStr("code"), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					neb::CJsonObject result;
					retJson.Get(XorStr("result"), result);

					result.Get(XorStr("endtime"), endtime);
					����ʱ��� = StringToDatetime(endtime);

					endtime = encode_str(endtime, �����ִ�����key);
					return true;
				}
				else
				{
					LastErroMsg = encode_str(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}

			else
			{
				LastErroMsg = encode_str(XorStr("����ʧ�ܣ�") , �����ִ�����key);
				return false;
			}
			return false;
		}
		//�ǳ�
		bool LogOut()
		{
			std::vector<Info> PostMsgInfo;
			Info api;
			api.Key = XorStr("action") ;
			api.Value = XorStr("logout") ;
			PostMsgInfo.push_back(api);
			Info Var1;
			Var1.Key = XorStr("user") ;
			Var1.Value = this->GetUser();
			PostMsgInfo.push_back(Var1);

			//����
			neb::CJsonObject retJson;
			if (HttpRequest(PostMsgInfo, retJson))
			{
				std::string codestr;
				retJson.Get(XorStr("code"), codestr);
				int code = std::stoi(codestr);
				if (code == 200)
				{
					return true;
				}
				else
				{
					LastErroMsg = encode_str(GetMessageWithErroCode(code), �����ִ�����key);
					return false;
				}
			}
			else
			{
				LastErroMsg = encode_str(XorStr("����ʧ�ܣ�") , �����ִ�����key);
				return false;
			}
			return false;
		}

	private:
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
			size_t Time = (size_t)time(NULL);
			std::string timeStr = std::to_string(Time);


			neb::CJsonObject json;
			json.Add(XorStr("sid") , this->Sid);
			json.Add(XorStr("uuid") , uuid);
			json.Add(XorStr("t") , Time);
			json.Add(XorStr("m1") , MD5(this->Sid + this->Key + timeStr).toString());
			json.Add(XorStr("m2") , this->Md5_2);
			json.Add(XorStr("m3") , this->Md5_3);
			json.Add(XorStr("mcode") , this->Mac_code);
			json.Add(XorStr("clientid") , this->ClientId);
			json.Add(XorStr("webkey") , this->WebKey);
			//�ɱ����
			for (size_t i = 0; i < Variable.size(); i++)
			{
				json.Add(Variable[i].Key, Variable[i].Value);
			}
			
			std::string out_json_text = json.ToString();
			

#ifdef _DEBUG
			std::cout << "���JSON���ģ�" << std::endl << out_json_text << std::endl;
			std::cout << std::endl;
#endif // _DEBUG

			//תΪUTF8����
			std::string UTF8_Str = STR_EC::GBKToUTF8(out_json_text);
			//����AES����
			std::string ���� = AES::Encryption(UTF8_Str, this->Key, nullptr, AES::PADDING::ZERO,AES::MODE::ECB_, AES::OUTMODE::HEX);
#ifdef _DEBUG
			std::cout << "�������ģ�" << std::endl << ���� << std::endl;
			std::cout << std::endl;
#endif // _DEBUG
			//����signƴ��
			std::string signƴ�� = this->SignRuleClient;
			signƴ�� = this->replace_all(signƴ��, XorStr("[data]"), ����);
			signƴ�� = this->replace_all(signƴ��, XorStr("[key]"), this->Key);
			std::string signֵ = MD5(signƴ��).toString();

			//����url���룬��ֹ��������ж�ʧ�����ַ�
			UrlEncoder url;
			std::string url���� = url.Encode(����, false);

			//���з�� 
			std::string ��� = XorStr("data=") + url���� + XorStr("&sign=") + signֵ;

			//��������ͷ
			httplib::Headers headers = 
			{
				{ "Accept", "*/*" },
				{ "Accept-Language", "zh-cn" }
			};

			//���ͷ��
			std::string ����ҳ = "/" + PageAddr;
			httplib::Client cli(Domain.c_str());
			auto res = cli.Post(����ҳ.c_str(), headers, ���.c_str(), "application/x-www-form-urlencoded");
			if (!res)
			{
				return false;
			}
			std::string �������� = res->body;


			/*************�����֤*******************/

			//ȡ��������sign
			neb::CJsonObject RetJson(��������);
			std::string RetData;
			std::string RetSign;
			RetJson.Get(XorStr("data"), RetData);
			RetJson.Get(XorStr("sign"), RetSign);

			//url����
			UrlEncoder RetUrl;
			std::string url����;
			RetUrl.Decode(RetData, &url����);
			//����signƴ��
			std::string Retsignƴ�� = this->SignRuleServer;
			Retsignƴ�� = this->replace_all(Retsignƴ��, XorStr("[data]"), url����);
			Retsignƴ�� = this->replace_all(Retsignƴ��, XorStr("[key]"), this->Key);
			std::string Retsignֵ = MD5(Retsignƴ��).toString();

			//У�����Ϸ���   1�Ա�signֵ�Ƿ���ȷ��2�Աȷ��uuid�Ƿ���ȷ��3�Աȷ��ʱ���Ƿ����̫����
			//�Ա�signֵ
			if (Retsignֵ != RetSign)
			{
				return false;
			}

			//DES����
			std::string ���ؽ������� = AES::Decryption(url����, this->Key, nullptr, AES::MODE::ECB_, AES::OUTMODE::HEX);

			std::string ret_string = STR_EC::UTF8ToGBK(���ؽ�������);

			RetJson_ = ret_string;
			std::string uuid_new;
			RetJson_.Get(XorStr("uuid"), uuid_new);
			int time_new = 0;
			RetJson_.Get(XorStr("t"), time_new);

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
				return(std::string(yearStr) + "/" + std::string(monthStr) + "/" + std::string(dayStr) + "/");
			}
			else if (hour_)
			{
				return(std::string(yearStr) + "/" + std::string(monthStr) + "/" + std::string(dayStr) + "/" + std::string(hourStr) + "/");
			}
			else if (minute_)
			{
				return(std::string(yearStr) + "/" + std::string(monthStr) + "/" + std::string(dayStr) + "/" + std::string(hourStr) + "/" + std::string(minuteStr) + "/");
			}
			else if (second_)
			{
				return(std::string(yearStr) + "/" + std::string(monthStr) + "/" + std::string(dayStr) + "/" + std::string(hourStr) + "/" + std::string(minuteStr) + "/" + std::string(secondStr) + "/");
			}
			else
			{
				return(std::string(yearStr) + "/" + std::string(monthStr) + "/" + std::string(dayStr) + "/" + std::string(hourStr) + "/" + std::string(minuteStr) + "/" + std::string(secondStr) + "/");
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

		//�����ִ�����AES����
		std::string encode_str(const std::string& strData, const std::string& password)
		{
			return AES::Encryption(strData, password, nullptr, AES::PADDING::ZERO, AES::MODE::CBC_, AES::OUTMODE::HEX);
		}
		//�����ִ�����AES����
		std::string decode_str(const std::string& strData, const std::string& password)
		{
			return AES::Decryption(strData, password, nullptr, AES::MODE::CBC_, AES::OUTMODE::HEX);
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
		//���ô�����Ϣ
		void SetLastErroMessage(std::string msg)
		{
			LastErroMsg = encode_str(msg, �����ִ�����key);

		}

	};

	std::map<size_t, std::string> CHwdNetWork::ErroMap =
	{
		{ 201 , XorStr("���������") },
		{ 202 , XorStr("ͨ����ԿУ��ʧ��") },
		{ 203 , XorStr("���MD5У��ʧ��") },
		{ 206 , XorStr("�˺Ż��������") },
		{ 207 , XorStr("��ֵ��������") },
		{ 209 , XorStr("��ǰ��������󶨻�������") },
		{ 210 , XorStr("�����˻��ѹ���,���ֵ���¼") },
		{ 211 , XorStr("�����˻�����Ϊ0,���ֵ���¼") },
		{ 212 , XorStr("���ά��") },
		{ 213 , XorStr("ͨ��֤����ͣ,��ֹ��¼") },
		{ 214 , XorStr("�����˻��ѹ���,�޷�ת��,ʹ�ñ�����ֵ���Զ���������") },
		{ 215 , XorStr("����ʣ��ʱ�䲻����֧��ת��۳�ʱ��,���ֵ.ʹ�ñ�����ֵ���Զ���������") },
		{ 216 , XorStr("ת��ʧ��,δ֪ԭ��,����ϵ�ͷ�����") },
		{ 217 , XorStr("�����˻�����Ϊ0,�޷�ת��,ʹ�ñ�����ֵ���Զ���������") },
		{ 218 , XorStr("����ʣ�����������֧��ת��۳�����,���ֵ.ʹ�ñ�����ֵ���Զ���������") },
		{ 219 , XorStr("��ֵ�˺Ų�����") },
		{ 220 , XorStr("��ֵ��������") },
		{ 221 , XorStr("��ֵ����Ŀ������,����ϵ�ͷ�") },
		{ 222 , XorStr("���ĳ�ֵ���뵱ǰ�˺����Ͳ���,�뵽�ں��ٳ�ֵ") },
		{ 223 , XorStr("���ĳ�ֵ���뵱ǰ�˺����Ͳ���,�뽫����������ٳ�ֵ") },
		{ 224 , XorStr("�۵��˻�������") },
		{ 225 , XorStr("��������,�۵�ʧ��") },
		{ 226 , XorStr("�۵�ʧ��,δ֪ԭ��,����ϵ�ͷ�") },
		{ 227 , XorStr("�˻�����ͣ,��ֹ��¼") },
		{ 228 , XorStr("ͨ��֤��ɾ��,��������") },
		{ 229 , XorStr("ͨ��֤�ѱ���ͣ,��������") },
		{ 230 , XorStr("����˻��ѱ�ɾ��,��������") },
		{ 231 , XorStr("����˻��ѱ���ͣ,��������") },
		{ 232 , XorStr("���ĵ���Ϊ0,��������") },
		{ 233 , XorStr("�����˻��ѵ���,��������") },
		{ 234 , XorStr("�����˻�������,�����ر�.") },
		{ 235 , XorStr("���¼���") },
		{ 236 , XorStr("�û����ϰ�ʧ��,δ֪ԭ��") },
		{ 237 , XorStr("��ʱ�˻�������") },
		{ 238 , XorStr("ʱ�䲻��,��ʱʧ��") },
		{ 239 , XorStr("��ʱʧ��,δ֪ԭ��,����ϵ�ͷ�") },
		{ 240 , XorStr("�����˺�����������,���Ժ�����,���쳣�˳�,��ȴ������Ӻ����µ�¼") },
		{ 241 , XorStr("��ֹת��") },
		{ 242 , XorStr("�Ƽ��˲�����") },
		{ 243 , XorStr("�û���Ϊ3-12λ,֧������") },
		{ 244 , XorStr("����Ϊ6-16λ") },
		{ 245 , XorStr("�û����Ѵ���,�����!") },
		{ 246 , XorStr("�����ѱ�ʹ��,�����!") },
		{ 247 , XorStr("ע��ʧ��,δ֪ԭ��.") },
		{ 248 , XorStr("�û������ڻ��ѱ���ͣ") },
		{ 249 , XorStr("�ʼ�����ʧ��,����ϵ�ͷ�����.") },
		{ 250 , XorStr("�ʼ���֤�����") },
		{ 251 , XorStr("�����޸�ʧ��,����ϵ�ͷ�����") },
		{ 252 , XorStr("��ʧ��,���󶨵�����û�������") },
		{ 253 , XorStr("�˻�δ��¼,���Զ���PHP����������") },
		{ 500 , XorStr("���ID����") },
		{ 601 , XorStr("����ʱ������������̫��,ͨ��ʧ��") },
		{ 602 , XorStr("�����ظ��ύ") },
	};

}

