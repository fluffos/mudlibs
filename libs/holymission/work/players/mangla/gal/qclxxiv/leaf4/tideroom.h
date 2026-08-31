inherit "/players/qclxxiv/leaf4/tideroom";
/* handy for tide-rooms */
#define LEAF4 "/players/qclxxiv/leaf4/"
int col;
int row;

/* to keep tideroom instantations small and simple: */
#define set_loc_and_exits(COL, ROW)\
	col = COL; row = ROW; set_tide_dest_dir(col,row); 

/* needed for tideroom.c itselve */
the_col() { return col; }
the_row() { return row; }
