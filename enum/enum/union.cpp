#include<string>
union Token {
public:
	char cval;
	int ival;
	double dval;
};
void tess(){
	Token fist_token = { 'a' };
	Token last_token;
	last_token.ival = 3;
	Token *pt = new Token;
}

namespace ss {
	static union {
		char cval;
		int ival;
		double dval;
	};
}

class mToken {
public:
	mToken():tok(INT),ival(0){}
	mToken(const mToken &t) :tok(t.tok) {
		copyUnion(t);
	}
	mToken &operator=(const mToken&);
	~mToken() {

	}
	mToken &operator=(const std::string&);
	mToken &operator=(char);
	mToken &operator=(int);
	mToken &operator=(double);
private:
	enum {
		INT,
		CHAR,
		DBL,
		STR
	} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
	};
	void copyUnion(const mToken&);
};
mToken &mToken::operator=(int i) {
	if (tok == STR)
		sval.~basic_string();
	ival = i;
	tok = INT;
	return *this;
}
mToken &mToken::operator=(const std::string &s) {
	if (tok == STR)
		sval = s;
	else {
		new (&sval) std::string(s);
	}
	tok = STR;
	return *this;
}
void mToken::copyUnion(const mToken &t) {
	switch (t.tok) {
	case mToken::INT:
		ival = t.ival;
		break;
	case mToken::CHAR:
		cval = t.cval;
		break;
	case mToken::DBL:
		dval = t.dval;
		break;
	case mToken::STR:
		new(&sval) std::string(t.sval);
		break;
	default:
		break;
	}
}
mToken &mToken::operator=(const mToken &t) {
	if (tok == STR&&t.tok != STR)
		sval.~basic_string;
	if (tok == STR&&t.tok == STR)
		sval = t.sval;
	else {
		copyUnion(t);
	}
	tok = t.tok;
	return *this;
}
void main() {

}
