#include "CHwdNetWork.hpp"
#include <iostream>

#pragma  warning(disable:4996)


using namespace std;



int main()
{

	//http://test.huweidun.cn/en.php?s=0f06bd6a57e775b3772176cea65f2af4
	/*
	
	TKKn7kH2qv1g0qEw6GMqHYwQm
TKZqBHycHJooINJFGiELfdHim
TKO1YkIfS6OiJy9zOp059ziJe
TKcvDFz4xmsG44Ju0n5Hbej0a
TKYJz82yL0DYi7Lk2MzpVwVUi
TK2P1MdadBlGdnKpHraEEjov0
TKW7IeeSPnBuLPQwABI8LwNtd
TKR2268AsUKe0ZrgiG1sqFa2Q
TK0WyCAVoJKnn8x2VDZKuIZ8C
TKLYv4uGmdy3qvlHSizdMJ1WP
	
	
	*/
	NETWORK::CHwdNetWork net
	(
		XorStr("Z6hDeN6k4RwWhsxAXRraa78O2nxp2sm8")/*ͨѶ��Կ*/,
		XorStr("eab84b7b-764f-47a2-9571-f5df21c1845b")/*���sid*/,
		XorStr(" ")/*������Ȩ����*/,
		XorStr("943e508419c4cd486ab894d3f7dbee50")/*������Ȩ����*/,
		XorStr("[data]123[key]abc")/*�ͻ���sign����*/,
		XorStr("[data]cba[key]321")/*�����sign����*/,
		80/*�������˿�*/,
		XorStr("test.huweidun.cn")/*��������ַ*/,
		XorStr("an.php?s=0f06bd6a57e775b3772176cea65f2af4")/*����ҳ*/
	);

	if (net.Init())
	{
		cout << "��ʼ���ɹ�"<<endl;
	}
	else
	{
		cout << "��ʼ��ʧ��" << endl;
		cout << net.GetLastErroMsg() << endl;
	}



	std::cout << "����:" << net.GetNotice() << std::endl;
	std::cout << "�������:" << net.GetName() << std::endl;
	std::cout << "����汾:" << net.GetVersion() << std::endl;
	std::cout << "�ͷ�qq:" << net.GetQq() << std::endl;
	std::cout << "������ص�ַ:" << net.GetDownloadurl() << std::endl;




	if (net.UserLogin("TKKn7kH2qv1g0qEw6GMqHYwQm","TKKn7kH2qv1g0qEw6GMqHYwQm"))
	{
		cout << "��¼�ɹ�" << endl;
	}
	else
	{
		cout << "��¼ʧ��" << endl;
		cout << net.GetLastErroMsg() << endl;
	}


	cout << "������ʱ����" << endl;


	if (net.DeductTime("10"))
	{
		cout << "��ʱ�ɹ�" << endl;
	}
	else
	{
		cout << "��ʱʧ��" << endl;
		cout << net.GetLastErroMsg() << endl;
	}

	if (net.BindMac("TKKn7kH2qv1g0qEw6GMqHYwQm"))
	{
		cout << "�󶨻����ɹ�" << endl;
	}
	else
	{
		cout << "�󶨻���ʧ��" << endl;
		cout << net.GetLastErroMsg() << endl;
	}








	return 0;
}

