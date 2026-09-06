#ifndef MXP_H
#include "/include/mxp.h"
#endif

/*
**   Function: process_mxp
**
**    Purpose: Process MXP.
**
** Parameters: string message, the message to transform
**
**    Returns: string
*/
public string
process_mxp(string message, int does_mxp) {
    int line = 0;
    int length = 0;
    int i = 0;
    int inTag = 0;
    int inEntity = 0;

    string *original_lines = explode(message, "\n");
    string *processed_lines = allocate(sizeof(original_lines));

    for (line = 0; line < sizeof(original_lines); line++) {
	processed_lines[line] = does_mxp ? MXPMODE(1) : "";

        length = sizeof(original_lines[line]);

        for (i = 0; i < length; i++) {
            if (inTag) { /* in a tag, eg. <send> */
                if (original_lines[line][i..i] == MXP_END) {
                    inTag = 0;

                    if (does_mxp) {
                        processed_lines[line] += ">";
                    }
                } else if (does_mxp) { /* copy tag only when MXP does_mxp */
                    processed_lines[line] += original_lines[line][i..i];
                }
            } else if (inEntity) { /* in a tag, eg. <send> */
                if (does_mxp) { /* copy tag only when MXP does_mxp */
                    processed_lines[line] += original_lines[line][i..i];
                }

                if (original_lines[line][i..i] == ";") {
                    inEntity = 0;
                }
            } else {
                if (original_lines[line][i..i] == MXP_BEG) {
                    inTag = 1;

                    if (does_mxp) {
                        processed_lines[line] += "<";
                    }
                } else if (original_lines[line][i..i] == MXP_END) { /* should not get this case */
                    processed_lines[line] += ">";
                } else if (original_lines[line][i..i] == MXP_AMP) {
                    inEntity = 1;

                    if (does_mxp) {
                        processed_lines[line] += "<";
                    }
                } else if (does_mxp) {
                    if (original_lines[line][i..i] == "<") {
                        processed_lines[line] += "&lt;";
                    } else if (original_lines[line][i..i] == ">") {
                        processed_lines[line] += "&gt;";
                    } else if (original_lines[line][i..i] == "&") {
                        processed_lines[line] += "&amp;";
                    } else if (original_lines[line][i..i] == "\"") {
                        processed_lines[line] += "&quot;";
                    } else {
                        processed_lines[line] += original_lines[line][i..i];
                    }
                } else { /* not MXP - just copy character */
                    processed_lines[line] += original_lines[line][i..i];
                }
            }
        }
    }

    return implode(processed_lines, "\n");
}
