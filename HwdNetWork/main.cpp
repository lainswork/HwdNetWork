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
	net = new NETWORK::CHwdNetWork(
		xorstr("YwqprshWcNdPksUUVnbaoox7boE73P6N").crypt_get()/*ͨѶ��Կ*/,
		xorstr("773c1e72-4d4a-4ef0-b970-bb4772c5a7b2").crypt_get()/*���sid*/,
		xorstr("ab310ac13de1e8c6c582b420bb014d05").crypt_get()/*ModuleMd5������Ȩ����*/,
		xorstr("e46f708329ce3f6c4d8cb1f7579f3d64").crypt_get()/*webkey*������Ȩ����*/,
		xorstr("[data]123123[key]asdfg").crypt_get()/*�ͻ���sign����*/,
		xorstr("[data]asdfg[key]123123").crypt_get()/*�ͻ���sign����*/,
		80/*�������˿�*/,
		xorstr("").crypt_get()/*��������ַ�磺127.0.0.1*/,
		xorstr("en.php?s=3f454239fd1a5385f1955449ba5a3b6f").crypt_get()/*����ҳ*/);

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

    system("pause");
	return 0;
}


