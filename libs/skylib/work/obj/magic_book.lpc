//  THOUGHT:
//      Disable the code for setup(), and the functions after it?  If we're
//      going to be inherited, it doesn't matter much, and will give the
//      book the OPTION of not being invulnerable, etc...
//


//  Okay, what IS a magic book?
//      It holds wizard spells.                     (ALWAYS)
//      It can't be torn.                           (ALWAYS)
//      Its order is randomized from time to time   (DEFAULT)
//      It is indexed (table of contents)           (DEFAULT)
//      Index is in in "wizard spells" language     (DEFAULT)
//      Index has " Table of Contents " header      (DEFAULT)
//      Index is at start of book                   (DEFAULT)
//      It has no title page.                       (DEFAULT)
//      Title page is in "sizard spells" language   (DEFAULT)
//
//  The defaults are geared according to what I assume to be the most
//  common set of needs for a spell book.
//
//  Except for being torn & lifted, use the following keywords:
//      "spell list",
//      ({
//          ({spell_file_name, spell_name}),
//              // ...
//      })
//          This introduces spells.  If {spell_name} is omitted, it is
//          infered from the {spell_file_name}.  E.g.,
//          "/w/wendell/spells/enchant" is infered to be "enchant".
//
//          ENHANCEMENT to consider:
//              Allow language to be specified?
//
//      "random", optional_boolean
//      "no random", optional_boolean
//          If you use ({"random", 0}), then you will force off
//          randomization of the spell order.  It defaults to on,
//          currently.
//
//      "index used", optional_boolean
//      "no index used", optional_boolean
//          This controls the existance of a table of contents into the
//          spell book.  Useful if you randomize the book but want (some)
//          players to be able to quickly find what they are looking for.
//
//      "index languge", language_name_string
//          This allows the index to be written in an arbitrary language
//          (needed to support the different discipline books).  This way,
//          a spell caster might be able to read the spells, but could have
//          trouble reading the index for the spells.
//
//          (IMPLICITLY TURNS ON "index used")
//
//      "index header", header_string
//          Normally, a typically badly spelled header line is put in the
//          table of contents.  You may wish to change this text, and this
//          permits you to do that.
//
//          (IMPLICITLY TURNS ON "index used")
//
//      "index at head", optional_boolean
//          Well, I sometimes call it the table of contents (which belongs
//          at the head of the book).  Other times, I call it the index,
//          and one could argue that THAT should go at the tail.  This lets
//          you decide for yourself.
//
//          (IMPLICITLY TURNS ON "index used")
//
//      "title page used", optional_boolean
//      "no title page used", optional_boolean
//          Let you put in a title page (probably irrelavent, with the
//          book's general read message & its long description).
//
//          If both exist, title-page will ALWAYS come before the index
//          page.
//
//      "title page", text_string
//          Will let you add a title page.
//
//          (IMPLICITLY TURNS ON "title page used")
//
//      "title page language"
//          Will let you set the langugae for the title page.
//
//          (IMPLICITLY TURNS ON "title page used")
//
//
//
//  All of those things might be made configurble...but for now, they all
//  hold.
//
//  Originally, I thought this might be taken by clone_object(), but the
//  use of that seems unlikely/rare enough that I'm just going to assume
//  ineritance.  clone_object() would be SLIGHLY more space conservative,
//  but...(shrug)  You can't easily duplicate the books, then, etc.
//
//      inherit MAGIC_BOOK;                 // /std/magic-book
//
//      /*** ... ***/
//
//      void setup ()
//      {
//          reset_get ();
//          set_short ("book");
//          add_adjective ("mgic");
//              /*** ... ***/
//          book_add_spells (SPELL_LIST);
//      }
//

inherit "/std/book";


int *build_order (int num)
{
    int *ret;
    int i;

    ret = allocate (num);
    for (i = 0; i < num; ++i)
        ret [i] = i;

    return (ret);
}

int *reorder (int *order)
{
    int i;
    int max;

    for (i = 0, max = sizeof (order); i < max; ++i)
    {
        int tmp;
        int swap;

        swap = random (max);
        tmp = order [swap];
        order [swap] = order [i];
        order [i] = tmp;
    }

    return (order);
}



string name_from_spell (mixed *spell)
{
    string ret;

    switch (sizeof (spell) )
    {
        case 0:
            ret = " <ERROR> ";
            break;

        case 1:
        {
            string *filesys_bits;

            filesys_bits = explode (spell [0], "/");
            ret = filesys_bits [sizeof (filesys_bits) - 1];
            break;
        }

        default:
            ret = spell [1];
            break;
    }

    return (ret);
}


mixed *spell_list;
int *order;

string index_header;
string index_lang;
int index_used;
int index_random;
int index_at_head;
int index_page;

string title_page;
string title_page_lang;
int title_page_used;


#define MAX(a,b) ( ( (a) < (b) ) ? (b) : (a) )
#define MIN(a,b) ( ( (a) > (b) ) ? (b) : (a) )
void book_do_config (mixed *config)
{
    int spell;
    int spells;
    string spell_index;
    int max_title_len;

    int spell_start_page;

    spell_list = ({ });
    index_header = " Table of Contents ";
    index_lang  = "wizard spells";
    index_used  = 1;
    index_random = 1;
    index_at_head = 1;

    title_page = "";
    title_page_lang = "wizard spells";
    title_page_used = 0;
    {
        int i;
        int limit;

        for (i = 0, limit = sizeof (config); i < limit; ++i)
        {
            string opt;
            int opt_is_array;
            mixed *opt_array;

            opt_is_array = pointerp (config [i]);
            if (!opt_is_array)
                opt = config [i];
            else
            {
                opt_array = config [i];
                opt = opt_array [0];
            }

            switch (opt)
            {
                case "spell list":
                    spell_list = opt_array [1];
                    break;


                case "random":
                    index_random = opt_is_array ? opt_array [1] : 1;
                    break;
                case "no random":
                    index_random = opt_is_array ? opt_array [1] : 0;
                    break;


                case "index used":
                    index_used = opt_is_array ? opt_array [1] : 1;
                    break;
                case "no index used":
                    index_used = opt_is_array ? opt_array [1] : 0;
                    break;

                case "index language":
                    index_lang = opt_array [1];
                    index_used = 1;                 // FORCE IT ON!
                    break;

                case "index header":
                    index_header = opt_array [1];
                    index_used = 1;                 // FORCE IT ON!
                    break;

                case "index at head":
                    index_at_head = opt_is_array ? opt_array [1] : 1;
                    index_used = 1;                 // FORCE IT ON!
                    break;


                case "title page used":
                    title_page_used = opt_is_array ? opt_array [1] : 1;
                    break;
                case "no title page used":
                    title_page_used = opt_is_array ? opt_array [1] : 0;
                    break;

                case "title page":
                    title_page = opt_array [1];
                    title_page_used = 1;            // FORCE IT ON!
                    break;

                case "title page language":
                    title_page_lang = opt_array [1];
                    title_page_used = 1;            // FORCE IT ON
                    break;


                default:
                    break;
            }
        }
    }

    //  JIC someone slipped us a non-0, non-1 value for these...
    //
    index_used = !!index_used;
    title_page_used = !!title_page_used;


    spell_start_page = 1;

    if (index_used && index_at_head)
        ++spell_start_page;

    if (title_page_used)
        ++spell_start_page;


    if (index_at_head)
        index_page = 1;
    else
        index_page = spells + spell_start_page - 1;

    if (title_page_used)
        ++index_page;


    spells = sizeof (spell_list);

    order = build_order (spells);
    if (index_random)
        order = reorder (order);

    set_no_pages (spells + index_used + title_page_used);
    max_title_len = strlen (index_header);
    spell_index = "";
    for (spell = 0; spell < spells; ++spell)
    {
        string spell_name;

        //  SHOULD expand_spell_list() (write a new function) to fill
        //  in default info for spell name and spell language.
        //
        spell_name = name_from_spell (spell_list [order [spell] ]);
        set_open_page (spell + spell_start_page);
        add_read_mess (spell_list [order [spell] ], 0, "wizard spells", 10);
        if (index_used)
        {
            spell_index +=
                    ( (spell < 8) ? "  " : " ")
                +   (spell + spell_start_page)
                +   " ... "
                +   spell_name
                +   "\n";
            max_title_len = MAX (max_title_len, strlen (spell_name) + 9);
        }
    }

    if ( index_used ) {
        spell_index = "\n"+ spell_index;
        for ( spell = 0; spell < ( max_title_len + 1 ) / 2; spell++ )
            spell_index = "=-"+ spell_index;
        spell_index = "\n"+ index_header +"\n-"+ spell_index;

        set_open_page(index_page);
        add_read_mess(spell_index, 0, index_lang, 10);
    }

    if( title_page_used ) {
        set_open_page( 1 );
        add_read_mess( title_page, 0, title_page_lang, 10 );
    }
    set_open_page (0);
}

//  Misc. stuff...
int do_tear(int number) { return 0; }

int query_binding_force () { return 100; }
