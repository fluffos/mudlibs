//m_gini.c 
private string m_gini;  // what is the type of gini
private int m_lastcall; 
private mapping m_gin_q;
void set_gini_q(string s,mixed v) {
	if(!mapp(m_gin_q))
		m_gin_q=([]);
	m_gin_q[s]=v;
}
mixed get_gini_q(string s) {
	if(!mapp(m_gin_q))
		m_gin_q=([]);
	if(!s) return m_gin_q;
	return m_gin_q[s];
}
void set_gini(string s) {
   m_gini=s;
}
string get_gini() {
   return m_gini;
}
void set_lastcall() {
   m_lastcall=time();
}
int query_lastcall() {
  return m_lastcall;
}
  