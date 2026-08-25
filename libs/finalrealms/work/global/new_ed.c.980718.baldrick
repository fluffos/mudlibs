// Call this when we're done editing.
private nosave function EndEditor;
//nosave function EndEditor;

// We can't tell how user exited ed(), so.
nosave string EdExitType;

// Editor code from Nanvaent <http://nanvaent.org/>                                    
//
// Put this player into the editor.
// This function starts an editor session for this player,
// the file given is edited.
//
// @param  fn    The name of the file to edit.
// @param  func  A function to call when the editor is exited.
//
varargs void begin_editing( string fn, function func )
{
    //int m = mortalp( this_object() );
    int m;

    if ( !this_object()->query_creator() ) 
      m = 1;
     else
      m = 0;

    EndEditor = func;
    ed_start( fn, m );

    // Start directly in edit mode if we're a player
    if( m || (file_size( fn ) <= 0) )
        ed_cmd( "$a" );
}

// Get the command used to exit the editor last.
//
// @return  The command. ie "q", "x" or "Q" usually.
//
string ed_exit_type() { return EdExitType; }

