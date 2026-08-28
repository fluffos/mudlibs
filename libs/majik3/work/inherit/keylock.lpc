
int locked;
int lock_diff;

string keycode;

void set_locked() { locked=1;}
void set_unlocked() { locked=0;}
void set_lock_difficulty(int i) { lock_diff=i;}
void set_key(string s) { keycode=s;}

int query_locked() { return locked;}
int query_lock_difficulty() { return lock_diff;}

string query_key() { return keycode;}


int fit_lock(object key)
{
    if(key->query_keycode()==keycode)
	return 1;
    return 0;
}
