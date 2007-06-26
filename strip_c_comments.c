#include <stdio.h>
#define IN 1
#define OUT 0

/*
 * This program strips out comments in C source files
 * See K&R v2, excercise 1-23.
 */
main ()
{
  /// pre-previous, previous and current character
  char ppc, pc, c;
  
  /// state is 'inside a block comment' flag;
  /// line_state is 'line comment was started' flag
  int state, line_state, string_state;

  state = line_state = string_state = OUT;
  c = pc = ppc = 0;
  
  while ((c = getchar()) != EOF) {
    /// All markup inside string is ignored
    if (string_state == OUT) {
      /// Line comment encountered?
      if ((c=='/') && (pc == '/'))
        line_state = IN;
      /// Comment block?
      /// @note ppc check to eliminate '*/*' case
      else if ((c == '*') && (pc == '/') && (ppc != '*'))
        state = IN;
      /// Did comment block end?
      if ((pc == '*') && (c == '/'))
        state = OUT;
    }
    
    /// String start/end?
    if (c == '\"')
      switch (string_state) {
      case IN: string_state = OUT; break;
      case OUT: string_state = IN; break;
      }
    
    if (c == '\n') {
      if (line_state == IN)
        printf("\n");
      line_state = OUT;
    }
    
    if ((state == OUT) && (line_state == OUT)) {
      if (string_state == IN)
        putchar(c);
      else {
        /// Suppress slash, as we cannot predict
        /// whether this slash will be a comment block delimiter or not.
        if (c != '/')
          putchar(c);
        /// Echo previously suppresed slash symbol
        if ((pc == '/') && (c != '*') && (ppc != '*'))
          putchar(pc);
      }
    }
    
    ppc = pc;
    pc = c;
  }
}
