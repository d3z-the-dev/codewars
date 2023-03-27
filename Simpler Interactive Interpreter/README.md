# [Simpler Interactive interpreter (or REPL)](https://www.codewars.com/kata/53005a7b26d12be55c000243)

You will create an interpreter which takes inputs described below and produces outputs, storing state in between each input. This is a simplified version of the Simple Interactive Interpreter kata with functions removed, so if you have fun with this kata, check out its big brother to add functions into the mix.

If you're not sure where to start with this kata, check out ankr's Evaluate Mathematical Expression kata.

Note that the `eval` command has been disabled.

### Concepts

The interpreter will take inputs in the language described under the language header below. This section will give an overview of the language constructs.

#### Variables

Any `identifier` which is not a keyword will be treated as a variable. If the identifier is on the left hand side of an assignment operator, the result of the right hand side will be stored in the variable. If a variable occurs as part of an expression, the value held in the variable will be substituted when the expression is evaluated.

Variables are implicitly declared the first time they are assigned to.

Example: Initializing a variable to a constant value and using the variable in another expression (Each line starting with a '>' indicates a separate call to the input method of the interpreter, other lines represent output)

```
>x = 7
    7
>x + 6
    13    
```

Referencing a non-existent variable will cause the interpreter to throw an error. The interpreter should be able to continue accepting input even after throwing.

**Example**: Referencing a non-existent variable

```
>y + 7
    ERROR: Invalid identifier. No variable with name 'y' was found."
```

#### Assignments

An assignment is an expression that has an identifier on left side of an = operator, and any expression on the right. Such expressions should store the value of the right hand side in the specified variable and return the result.

**Example**: Assigning a constant to a variable

```
x = 7
    7
```

In this kata, all tests will contain only a single assignment. You do not need to consider chained or nested assignments.

#### Operator Precedence

Operator precedence will follow the common order. There is a table in the Language section below that explicitly states the operators and their relative precedence.

#### Name conflicts

Because variables are declared implicitly, no naming conflicts are possible. variable assignment will always overwrite any existing value.

#### Input

Input will conform to the expression production in the grammar below.

#### Output

Output for a valid expression will be the result of the expression.

Output for input consisting entirely of whitespace will be an empty string (null in case of Java).

All other cases will throw an error.

### Language

#### Grammar

This section specifies the grammar for the interpreter language in EBNF syntax

```
expression      ::= factor | expression operator expression
factor          ::= number | identifier | assignment | '(' expression ')'
assignment      ::= identifier '=' expression

operator        ::= '+' | '-' | '*' | '/' | '%'

identifier      ::= letter | '_' { identifier-char }
identifier-char ::= '_' | letter | digit

number          ::= { digit } [ '.' digit { digit } ]

letter          ::= 'a' | 'b' | ... | 'y' | 'z' | 'A' | 'B' | ... | 'Y' | 'Z'
digit           ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
```

### Operator Precedence

The following table lists the language's operators grouped in order of precedence. Operators within each group have equal precedence.

| Category       | Operators |
|----------------|-----------|
| Multiplicative | *, /, %   |
| Additive       | +, -      |
| Assignment     | =         |
