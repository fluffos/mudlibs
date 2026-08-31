#ifndef __COLOUR_H__
#define __COLOUR_H__

#define RESET_REGEX \
"\\{\\{res\\}\\}"   "|" \
"\\{\\{RES\\}\\}"

#define ATTRIBUTE_REGEX \
"\\{\\{(re|it|ul|fl|st|bl|di|ol)[0-1]\\}\\}"

// FG: {{000}} - {{fff}} | {{000000}} - {{ffffff}}
#define TRUE_COLOUR_REGEX    \
"\\{\\{((?:"                 \
"[a-fA-F0-9]{6}"       "|"  \
"[a-fA-F0-9]{3}"            \
"))\\}\\}"

// BG: ^^000^^ - ^^fff^^ | ^^000000^^ - ^^ffffff^^
#define BG_TRUE_COLOUR_REGEX \
"\\{\\^((?:"                 \
"[a-fA-F0-9]{6}"       "|"  \
"[a-fA-F0-9]{3}"            \
"))\\^\\}"

#define COLOUR_REGEX      \
RESET_REGEX           "|" \
ATTRIBUTE_REGEX       "|" \
TRUE_COLOUR_REGEX     "|" \
BG_TRUE_COLOUR_REGEX

#define HEX_CHECK_3 "^#?[a-fA-F0-9]{3}$"
#define HEX_CHECK_6 "^#?[a-fA-F0-9]{6}$"
#define HEX_CHECK   "^#?(?:[a-fA-F0-9]{6}|[a-fA-F0-9]{3})$"

#define SYSTEM_OK       "{{009966}}"
#define SYSTEM_ERROR    "{{CC0000}}"
#define SYSTEM_WARNING  "{{FF9900}}"
#define SYSTEM_INFO     "{{0099CC}}"
#define SYSTEM_QUERY    "{{0066FF}}"
#define SYSTEM_DEBUG    "{{CC00CC}}"

#endif // __COLOUR_H__
