#include "CHwdNetWork.h"
#include "XorString.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/pem.h>
#include <openssl/err.h>

//��֤����
NETWORK::CHwdNetWork* net = nullptr;

int main()
{


    /*�ڴ˴���д���λ��ص���Ϣ����������������������*/
	net = new NETWORK::CHwdNetWork(
		xorstr("oudHA6NQ2YYC9b3D36xxXGoR3RkM5T7s").crypt_get()/*ͨѶ��Կ*/,
		xorstr("c398ebb5-114c-4258-bb5e-d97bff7a370b").crypt_get()/*���sid*/,
		xorstr("ab310ac13de1e8c6c582b420bb014d05").crypt_get()/*ModuleMd5������Ȩ����*/,
		xorstr("e46f708329ce3f6c4d8cb1f7579f3d64").crypt_get()/*webkey*������Ȩ����*/,
		xorstr("[data]123[key]abc").crypt_get()/*�ͻ���sign����*/,
		xorstr("[data]cba[key]321").crypt_get()/*�����sign����*/,
		80/*�������˿�*/,
		xorstr("").crypt_get()/*��������ַ�磺127.0.0.1*/,
		xorstr("en.php?s=8d703e0cf4c7f1434c4540a1f2066cc3").crypt_get()/*����ҳ*/);

    static size_t ����� = 0;
    static bool isOk = false;
    while (!(isOk = net->Init()) && ����� < 3) { �����++; };
    if (!isOk)
    {
        std::string ��ʾ = std::string(xorstr("�����ʼ��ʧ�ܣ��������绷����").crypt_get()) + net->GetLastErroMsg();
        MessageBoxA(NULL, ��ʾ.c_str(), xorstr("����").crypt_get(), MB_OK);
        return 0 ;
    }

    std::cout << "����:" << net->GetNotice() << std::endl;
    std::cout << "�������:" << net->GetName() << std::endl;
    std::cout << "����汾:" << net->GetVersion() << std::endl;
    std::cout << "�ͷ�qq:" << net->GetQq() << std::endl;
    std::cout << "������ص�ַ:" << net->GetDownloadurl() << std::endl;

    if (net->UserLogin("HZUWCFF6n39MEBQK", "HZUWCFF6n39MEBQK"))
    {
        std::cout << "��¼�ɹ�" << std::endl;
        std::cout << "���"<<net->GetPoint() << std::endl;
    }
    else
    {
        std::cout << "��¼ʧ��" << std::endl;
        std::cout << "ԭ��" << net->GetLastErroMsg() << std::endl;
    }
    if (net->DeductPoint("1", NETWORK::DEDUCTPOINTMODE::ONEDAY_ONCE))
    {
        std::cout << "�۵�ɹ�" << std::endl;
        std::cout << "��" << net->GetPoint() << std::endl;
    }
    else
    {
        std::cout << "�۵�ʧ��" << std::endl;
        std::cout << "ԭ��" << net->GetLastErroMsg() << std::endl;
    }



    system("pause");
	return 0;
}


