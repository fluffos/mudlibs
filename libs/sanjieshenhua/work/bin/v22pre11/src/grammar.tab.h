#ifndef BISON_Y_TAB_H
# define BISON_Y_TAB_H

#ifndef YYSTYPE
typedef union

{
    POINTER_INT pointer_int;
    int number;
    float real;
    char *string;
    int type;
    struct { short num_arg; char flags; } argument;
    ident_hash_elem_t *ihe;
    parse_node_t *node;
    function_context_t *contextp;
    struct {
	parse_node_t *node;
        char num;
    } decl; /* 5 */
    struct {
	char num_local;
	char max_num_locals; 
	short context; 
	short save_current_type; 
	short save_exact_types;
    } func_block; /* 8 */
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
# define	L_STRING	257
# define	L_NUMBER	258
# define	L_REAL	259
# define	L_BASIC_TYPE	260
# define	L_TYPE_MODIFIER	261
# define	L_DEFINED_NAME	262
# define	L_IDENTIFIER	263
# define	L_EFUN	264
# define	L_INC	265
# define	L_DEC	266
# define	L_ASSIGN	267
# define	L_LAND	268
# define	L_LOR	269
# define	L_LSH	270
# define	L_RSH	271
# define	L_ORDER	272
# define	L_NOT	273
# define	L_IF	274
# define	L_ELSE	275
# define	L_SWITCH	276
# define	L_CASE	277
# define	L_DEFAULT	278
# define	L_RANGE	279
# define	L_DOT_DOT_DOT	280
# define	L_WHILE	281
# define	L_DO	282
# define	L_FOR	283
# define	L_FOREACH	284
# define	L_IN	285
# define	L_BREAK	286
# define	L_CONTINUE	287
# define	L_RETURN	288
# define	L_ARROW	289
# define	L_INHERIT	290
# define	L_COLON_COLON	291
# define	L_ARRAY_OPEN	292
# define	L_MAPPING_OPEN	293
# define	L_FUNCTION_OPEN	294
# define	L_NEW_FUNCTION_OPEN	295
# define	L_SSCANF	296
# define	L_CATCH	297
# define	L_PARSE_COMMAND	298
# define	L_TIME_EXPRESSION	299
# define	L_CLASS	300
# define	L_NEW	301
# define	L_PARAMETER	302
# define	LOWER_THAN_ELSE	303
# define	L_EQ	304
# define	L_NE	305


extern YYSTYPE yylval;

#endif /* not BISON_Y_TAB_H */
