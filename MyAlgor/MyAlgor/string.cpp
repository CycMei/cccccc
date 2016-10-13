#include<string>
#include<iostream>
using std::string;
//����ͳ�ʼ��string
namespace init {
	void str() {
		string s1;				//Ĭ�ϳ�ʼ����s1�Ǹ����ַ���
		string s2 = s1;			//s2��s1�ĸ������ȼۣ� string s2(s1);
		string s3 = "hiya";		//s3�Ǹ��ַ�������ֵ�ĸ������ȼۣ�string s3("hiya");
		string s4(10, 'c');		//s4��������10��c�������ʼֵֻ����ֱ�ӳ�ʼ��������������ʼ��Ҳ���ԣ�string s4=string(10,'c');�и���ʱ����
	}
	void extend() {
		const char *cp = "Hello Word!!!";	//�Կ��ַ�����������
		char noNull[] = { 'H','i' };		//���Կ��ַ�����������
		string s1(cp);						//����cp�е��ַ�֪���������ַ�
		string s2(noNull, 2);				//��noNull�п���2���ַ���ǰ2���ַ��Ŀ���
		//string s3(noNull);				//δ���壬noNull�����Կ��ַ�����������
		string s4(cp + 6, 5);				//��cp[6]��ʼ����5���ַ�
		string s5(s1, 6, 5);				//��s1[6]��ʼ����5���ַ�
		string s6(s1, 6);					//��cp[6]��ʼ����ֱ��s1��ĩβ������ڶ����������ڵ�һ��������size(),���캯��δ����
		string s7(s1, 6, 20);				//��s1[6]��ʼ��࿽����s1��ĩβ������ڶ����������ڵ�һ��������size(),���캯��δ����
		string s8(s1, 16);					//����ڶ����������ڵ�һ��������size(),���캯��δ���壬�׳�out_of_range
	}
};
//����
namespace contr {
	//ios
	void ios(){
		string s;
		std::cin >> s;				//��string�������s������cin��string������Զ����Կ�ͷ�Ŀհף���һ���������ַ���ȡ��ֱ��������һ���հ�
		std::cout << s << std::endl;//��sд��cout�У�����cout
	}
	void mgetline() {
		string line;
		//std::getline�������Ǳ���is,string���Ͷ��󡣷�����������Ϊ�˱�������ʱ�Ŀհ׷�
		//�����ж�ȡ����ֱ���������з������з�Ҳ����������
		//Ȼ���������ݴ��뵽string����ȥ�����з����档
		//getline�������з��ͽ�����ȡ�����������ؽ�������һ��ʼ�ǻ��з�������ǿ�string
		while (std::getline(std::cin, line)) {
			std::cout << line << std::endl;
		}
	}
	void othercontr() {
		string s1("hello word");
		s1.empty();		//s1Ϊ�շ���true�����򷵻�false
		string::size_type count=s1.size();		//s1�����е��ַ�����,size_type���޷������ͣ���sting size()�����ĵط���Ҫʹ��int
	}
	bool comparestr() {
		//sting �Ƚ����������һ�Ƚ�string�����е��ַ����Դ�Сд����
		//==,!=��2��string����ĳ��Ⱥ����������ַ�Ҳ��ͬ�����򲻵�
		//<,<=,>,>=���ֵ�˳��
		//1.���2��string����ĳ��Ȳ�ͬ�����ҽ϶̵Ķ����ÿ���ַ�����ϳ���string�����Ӧλ���ϵ��ַ���ͬ����̵�stringС�ڳ���string����
		//2.���2��string������ĳЩλ���ϲ�һ�£��������string�����е�һ�������ַ��ȽϽ��
		string str = "Hello";
		string phrase = "Hello World";
		string slang = "Hiya";
		if (str < phrase)
			return true;
		if (phrase < slang)
			return true;
	}
	void opratoreuql() {
		string str(10, 'c'), stc;
		stc = str;				//����ֵ
		string s1 = "hello, ", s2 = "world\n";
		string s3 = s1 + s2;	//�������
		s1 += s2;
		//����ֵ��string����+��������������������һ����string����
		string s4 = s1 + ",";
	}
	void msubstr() {
		//substr ����һ��string����ԭʼ��һ���ֻ���ȫ���Ŀ����������ṩһ����ʼλ�úͼ���ֵ
		string s("hello world");
		string s2 = s.substr(0, 5);		//��s[0]��ʼ����5��
		string s3 = s.substr(6);		//��s[6]������ĩβ
		string s4 = s.substr(6, 11);	//��s[6]��࿽����ĩβ
		string s5 = s.substr(12);		//��ʵλ�ó���size()���׳�out_of_range
	}
	void minsert() {
		string s("hello world");
		s.insert(s.size(), 5, '!');		//��s.size()֮ǰ����5��!;�����±�ķ���s�����ã����ܵ������ķ���ָ���һ���ַ�����ĵ�����
		s.erase(s.size() - 5, 5);		//ɾ����s.szie()-5��ʼ��5���ַ�������һ��ָ��s������
		const char *cp = "skdlwkdffkdkddkd";
		s.assign(cp, 7);				//��s�е��ַ����滻Ϊcpָ��ĵ�ַ��ʼ��7���ַ�����������
		s.insert(s.size(), cp + 7);		//����cp+7֮ǰ���ַ�
		string s2 = "dwddd";
		s.insert(0, s2);
		s.insert(0, s2, 0, s2.size());
	}
	void mappend() {
		string s("c++ primer"), s2 = s;
		s2.append("dksl");				//��s2��ĩβ�����ַ�����������
	}
	void mreplace() {
		string s("c++ primer"), s2 = s;
		s2.replace(2, 4, "dda");		//ɾ��2��ʼ��4���ַ������������ַ� ��������
	}
	//���кܶ�ܶ� ����д
};