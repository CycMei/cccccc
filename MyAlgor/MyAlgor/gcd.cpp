unsigned int InstanceGcd(int les, int res) {
	if (res == 0)
		return les;
	else {
		int result = InstanceGcd(res, les%res);
		return result;
	}
}
template<typename T1,typename T2> unsigned int TempLateGcd(T1 t1, T2 t2) {
	return InstanceGcd(t1, t2);
}
template<typename T1,typename T2, typename... Args> unsigned int TempLateGcd(T1 t1,T2 t2, Args... rest) {
	unsigned int result= InstanceGcd(t1, t2);
	return TempLateGcd(result, rest...);
}