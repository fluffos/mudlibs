#ifndef __LETTERS_H
#define __LETTERS_H

nosave private int valid_access();
string create_letter(string str);
nosave private void save_letter();
nosave private int restore_letter(string id);
string query_letter(string id);
void delete_folder(string who, string folder, string id);
void add_folder(string who, string folder, string id);
nosave void manage_letters();
nosave void manage_postal();

#endif /* __LETTERS_H */
