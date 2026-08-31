
mapping multi_quests;

varargs mapping query_multi_quests(string m_quest_name) {
    string* m_quest_return;
    if(!multi_quests) return ([]);
    if(!m_quest_name) return multi_quests;
    return member_array(m_quest_name,keys(multi_quests)) ?

    multi_quests[m_quest_name] : ([]); }
