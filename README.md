<!-- markdownlint-disable MD033 MD031 -->
# Obfuscated C - Twelve Days of Christmas

This repository explains how to methodically "unobfuscate" the winning [1988 International Obfuscated C Contest](https://www.ioccc.org/years.html#1988) entry, from [phillipps](https://www.ioccc.org/1988/phillipps.c).

Following the "obfuscation" theme, entries are identified by the author's name. Later this program became known as the "Twelve Days of Christmas", which already hints at what it does. For a while, it circulated widely and even became the [example in a paper about code analysis](https://dl.acm.org/doi/10.1145/318774.318944) (which also decodes it -- it's a great read).

We will methodically modify the code until it becomes intelligible C code. Some of the steps could be combined into one step. However, the intention is to make one change at a time to see how each transformation makes the code better and also to backtrack only one change, in case it doesn't work (as it happens in real-life examples -- a good rule of thumb for experiments and research is "make one change at a time").

We will start with this:

<details>
  <summary>Click to see the obfuscated code</summary>

```c
// This is the original program, just modified to work with a modern C compiler
f(t, _, a) char *a;
{
    return !0 < t ? t < 3 ? f(-79, -13, a + f(-87, 1 - _, f(-86, 0, a + 1) + a)) : 1, t < _ ? f(t + 1, _, a) : 3, f(-94, -27 + t, a) && t == 2 ? _ < 13 ? f(2, _ + 1, "%s %d %d\n") : 9 : 16 : t < 0 ? t < -72 ? f(_, t, "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+,/#\;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l \q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# \){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' \iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c \;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# \}'+}##(!!/") : t < -50 ? _ == *a ? putchar(31 [a]) : f(-65, _, a + 1) : f((*a == '/') + t, _, a + 1) : 0 < t ? f(2, 2, "%s") : *a == '/' || f(0, f(-61, *a, "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry"), a + 1);
}

int main(int argc, char *argv[])
{
    // The original program ("main(t,_,a)) makes a decision based on "t", which is argc
    // When called with no arguments, argc == 1, so we emulate that by calling
    // the new function once with 1 as the first parameter to get it started
    f(1, 0, 0);
}
```
</details>

<br>
And arrive at this:

<details>
  <summary>Click to see the "unobfuscated" code</summary>

```c
char *encoded_text =
    "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+"
    ",/#\;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l \q#'+d'K#!/+k#;q#"
    "'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# \){nl]!/n{n"
    "#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' \iwk{KK{nl]!/w"
    "{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c \;;{nl'-{}rw]'/+,}##'*}#n"
    "c,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# \}'+}##(!!/";

char *cipher =
    "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:"
    "\nuwloca-O;m .vpbks,fxntdCeghiry";

void decode_text(char *text) {
    while (*text != '/') {
        char *p = cipher;
        while (*text != *p) p++;
        putchar(p[31]);
        text++;
    }
}

void move_to_segment_and_decode(int segment) {
    int slashes_so_far = 0;
    char *p = encoded_text;
    while (slashes_so_far < segment) {
        if (*p++ == '/') {
            slashes_so_far++;
        }
    }
    decode_text(p);
}

void print_day_preamble(int day) {
    decode_text(encoded_text);
    move_to_segment_and_decode(day);
    move_to_segment_and_decode(13);
}

int main(int argc, char *argv[]) {
    for (int day = 1; day < 13; day++) {
        print_day_preamble(day);
        for (int i = day + 1; i >= 2; i--) {
            move_to_segment_and_decode(27 - i);
        }
    }
}
```
</details>

## The original code

The starting point is the [original code, modified to work with a modern C compiler](./phillipps.c). You should be able to compile it with `gcc` and run it with `./a.out`. It will (incredibly) print the [Twelve Days of Christmas song](https://en.wikipedia.org/wiki/The_Twelve_Days_of_Christmas_(song)).

Compiling the code will result in several warnings because of the intentionally convoluted style but no errors. Despite the warnings, it's a perfectly legal piece of C code.

```bash
$ gcc phillipps01.c
$ ./a.out
On the first day of Christmas my true love gave to me
a partridge in a pear tree.
...
```

## Step 1 - split data from code

In this step we separate the large strings from the code. The goal is to help see the code structure better.

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps.c](./phillipps.c) (original code) | [phillipps-step-01.c](./phillipps-step-01.c) |

## Step 2 - improve formatting

Now that data and code are split, we can format (pretty print) the code to see the decision paths.

The goal is to go from code like this:

```c
return !0 < t ? t < 3 ? f(-79, -13, a + f(-87, 1 - _, f(-86, 0, a + 1) + a)) : 1,
...
```

To code like this:

```c
    return
    !0 < t ?
        t < 3 ?
            f(-79, -13, a + f(-87, 1 - _, f(-86, 0, a + 1) + a))
        :
            1,
...
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-01.c](./phillipps-step-01.c) | [phillipps-step-02.c](./phillipps-step-02.c) |

## Step 3 - make the code structure more visible with if/else

The ternary operator (?:) is not a common code structure. In this step we translate it to traditional if/else blocks that are easier to follow.

The goal is to go from code like this:

```c
    !0 < t ?
        t < 3 ?
            f(-79, -13, a + f(-87, 1 - _, f(-86, 0, a + 1) + a))
        :
            1,
...
```

To code like this:

```c
     if (!0 < t) {
        if (t < 3) {
            f(-79, -13, a + f(-87, 1 - _, f(-86, 0, a + 1) + a));
        } else {
            1;
        }
...
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-02.c](./phillipps-step-02.c) | [phillipps-step-03.c](./phillipps-step-03.c) |

## Step 4 – make the code more readable

In this step we make the code more readable with the following changes:

1. Replace the test `if (!0 < t)` with the more traditional `if (t > 1)`.
1. Replace the implicit `if` from the short-circuit evaluation `*a == '/' || f...` with an explicit if/else.
1. Split embedded function calls into separate calls.
1. Remove `else` branches that don't executable code, just numbers.

The goal is to go from code like this:

```c
     if (!0 < t) {
        if (t < 3) {
            f(-79, -13, a + f(-87, 1 - _, f(-86, 0, a + 1) + a));
        } else {
            1;
        }
...
```

To code like this:

```c
    if (t > 1) {
        if (t < 3) {
            int tmp1 = f(-86, 0, a + 1);
            int tmp2 = f(-87, 1 - _, tmp1 + a);
            f(-79, -13, a + tmp2);
        }
...
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-03.c](./phillipps-step-03.c) | [phillipps-step-04.c](./phillipps-step-04.c) |

## Step 5 – simplify "else" branches

Because most of the if/else constructs have `return` statements, we can remove some of the `else` branches, "promoting" their code to a higher level, making the decision paths easier to follow.

The goal is to go from code like this:

```c
        if (f(-94, -27 + t, a) && t == 2) {
            if (_ < 13) {
                return f(2, _ + 1, "%s %d %d\n");
            } else {
                return 9;
            }
        } else {
            return 16;
        }
...
```

To code like this:

```c
        if (f(-94, -27 + t, a) && t == 2) {
            if (_ < 13) {
                return f(2, _ + 1, "%s %d %d\n");
            }
            return 9;
        }
        return 16;
...
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-04.c](./phillipps-step-04.c) | [phillipps-step-05.c](./phillipps-step-05.c) |

## Step 6 – simplify decisions paths

Some of the decision paths in the code are redundant. For example, in the code…

```c
    if (t < 0) {
        if (t < -72) {
```

…the second `if` can be moved up because the 't < 0` test is redundant.

In this sequence…

```c
    if (t > 1) {
        if (t < 3) {
```

… `t` can only be `2`, so it will be made explicit.

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-05.c](./phillipps-step-05.c) | [phillipps-step-06.c](./phillipps-step-06.c) |

## Step 7 – rearrange "if" statements

Let's rearrange the `if` statements in increasing numeric order to make it easier to follow the paths in the code.

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-06.c](./phillipps-step-06.c) | [phillipps-step-07.c](./phillipps-step-07.c) |

## Step 8 – Use constants

At this point, it is clear that `t` is used to control the action the code takes. Instead of using magic numbers for `t`, let's change to constants to make it easier to follow what branch of the code is being executed in the next call, and what that branch of code does.

Also, use better names for the function parameters (still cryptic, but at least now their order is apparent in their names).

Because the purpose of the code is more apparent with the constants in place, we can also add comments to the blocks of code that execute specific functions.

The goal is to go from code like this:

```c
f(t, _, a) char *a;
{
    if (t == 0) {
        if (*a == '/') {
            return 1;
        }
        int tmp = f(-61, *a, small_string);
        return f(0, tmp, a + 1);
    }
...
```

To code like this:

```c
f(p1, p2, p3) char *p3;
{
    // Called recursively until a "/" is found in p3
    if (p1 == GO_TO_SLASH) {
        if (*p3 == '/') {
            return 1;
        }
        int tmp = f(ADVANCE_OR_PRINT, *p3, small_string);
        return f(GO_TO_SLASH, tmp, p3 + 1);
    }
...
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-07.c](./phillipps-step-07.c) | [phillipps-step-08.c](./phillipps-step-08.c) |

## Step 9 - simplify `SWAP_VARIABLES`

With the constants in place, we can see that when the code enters the `SWAP_VARIABLES` branch, the third parameter is not used:

```c
    // Swap p1 and p2
    if (p1 < (SWAP_VARIABLES+1)) {
        return f(p2, p1, large_string);
    }
```

It always uses the large string as the third parameter. We can simplify the code based on that. Whenever we call the function with `SWAP_VARIABLES` as the first parameter, we can simply ignore the third parameter (in other words, the original code uses the third parameter to obfuscate the code, but it's not really needed).

We can go from this:

```c
    if (p1 == 2) {
        int tmp1 = f(SWAP_VARIABLES, 0, p3 + 1);
        int tmp2 = f(SWAP_VARIABLES, 1 - p2, tmp1 + p3);
        f(SWAP_VARIABLES, -13, p3 + tmp2);
    }
```

To this:

```c
    if (p1 == 2) {
        f(SWAP_VARIABLES, 0, 0);
        f(SWAP_VARIABLES, 1 - p2, 0);
        f(SWAP_VARIABLES, -13, 0);
    }
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-08.c](./phillipps-step-08.c) | [phillipps-step-09.c](./phillipps-step-09.c) |

## Step 10 - eliminate `SWAP_VARIABLES`

After simplifying `SWAP_VARIABLES`, it becomes clear that it is just misdirection. It can be replaced with direct calls to the function, with the variables already swapped.

We can replace this:

```c
    if (p1 == 2) {
        f(SWAP_VARIABLES, 0, 0);
        f(SWAP_VARIABLES, 1 - p2, 0);
        f(SWAP_VARIABLES, -13, 0);
    }
```

With direct calls to the function with the variables already swapped:

```c
    if (p1 == 2) {
        f(GO_TO_SLASH, 0, large_string);
        f(1 - p2, 0, large_string);
        f(-13, 0, large_string);
    }
```

Also, the third parameter is not used when the function is called with `p1 == 2`. We can remove some bogus strings used in those cases to remove clutter from the code (more obfuscation).

For example, this call with `p1` set to `2`:

```c
    if (p1 == 1) {
        return f(2, 2, "%s");
    }
```

Can be replaced with this, since the third parameter is not used with `p1` is `2`:

```c
    if (p1 == 1) {
        return f(2, 2, 0);
    }
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-09.c](./phillipps-step-09.c) | [phillipps-step-10.c](./phillipps-step-10.c) |

## Step 11 – remove branch that handles `p1 == 1`

The branch of code that handles `p1 == 1` is hard-coded to call the function again, just changing `p1` to `2`. We can simply call the function the first time with `p1` set to `2`.

This code can be removed:

```c
    if (p1 == 1) {
        return f(2, 2, 0);
    }
```

And the first call to the function can start with `p1` set to `2` instead of `1`:

```c
int main(int argc, char *argv[]) {
    // Call with the value that kicks off the code (2)
    f(2, 2, 0);
}
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-10.c](./phillipps-step-10.c) | [phillipps-step-11.c](./phillipps-step-11.c) |

## Step 12 - replace recursion to print characters with a loop

The recursion in the `ADVANCE_OR_PRINT` branch is used only to advance the pointer to the character we want to print. It can be replaced with a simple loop to make the code easier to follow. We can also then rename `ADVANCE_OR_PRINT` to simply `PRINT`.

This code:

```c
    // Find p2 in p3 and print it
    if (p1 < (ADVANCE_OR_PRINT + 1)) {
        if (p2 == *p3) {
            return putchar(p3[31]);
        }
        return f(ADVANCE_OR_PRINT, p2, p3 + 1);
    }
```

Becomes:

```c
    // Find p2 in p3 and print it
    if (p1 < (PRINT + 1)) {
        while (p2 != *p3) p3++;
        return putchar(p3[31]);
    }
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-11.c](./phillipps-step-11.c) | [phillipps-step-12.c](./phillipps-step-12.c) |

## Step 13 – improve `GO_TO_SLASH`

After improving the (new) `PRINT`, it is more apparent now that `GO_TO_SLASH` is not only going to a slash but printing each character along the way (i.e. it's printing a piece of the text). To make it easier to follow, the recursion is replaced with a loop.

The `GO_TO_SLASH` constant is renamed to `PRINT_ONE_PIECE` to reflect better what it does, and `PRINT` is renamed to `PRINT_ONE_LETTER` to distinguish the two constants.

This code:

```c
    if (p1 == GO_TO_SLASH) {
        if (*p3 == '/') {
            return 1;
        }
        int tmp = f(PRINT, *p3, small_string);
        return f(GO_TO_SLASH, tmp, p3 + 1);
    }
```

Become this code:

```c
    if (p1 == PRINT_ONE_PIECE) {
        while (*p3 != '/')
            f(PRINT_ONE_LETTER, *p3++, small_string);
        return 1;
    }
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-12.c](./phillipps-step-12.c) | [phillipps-step-13.c](./phillipps-step-13.c) |

## Step 14 - combine printing code

The code that prints one character is now called from only one place (from the block of code that prints a piece of text). To simplify the flow, that code is moved into the place that calls it.

These two pieces of code are combined into one:

```c
    if (p1 == PRINT_ONE_PIECE) {
        while (*p3 != '/')
            f(PRINT_ONE_LETTER, *p3++, small_string);
        return 1;
    }
...
    // Find p2 in p3 and print it
    if (p1 < (PRINT_ONE_LETTER + 1)) {
        while (p2 != *p3) p3++;
        return putchar(p3[31]);
    }
```

Becoming this code (and eliminating the `PRINT_ONE_LETTER` constant):

```c
    if (p1 == PRINT_ONE_PIECE) {
        while (*p3 != '/') {
            char *p = small_string;
            while (*p3 != *p) p++;
            putchar(p[31]);
            p3++;
        }
        return 1;
    }
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-13.c](./phillipps-step-13.c) | [phillipps-step-14.c](./phillipps-step-14.c) |

## Step 15 - split out the code that prints a piece of text

To help see the logic of the main function, the code that prints one piece of text is moved to its own function:

```c
void decode_text(char* text) {
    while (*text != '/') {
        char *p = small_string;
        while (*text != *p) p++;
        putchar(p[31]);
        text++;
    }
}
```

It is now clear that the small string is acting as a cipher: a character from the large string is translated into a character 31 positions ahead in the small string.

The call to decide the text when `p1 == 2` is also replaced with a direct call to the decode function. This makes it clearer that `p1 == 2` is the initialization code for the program.

Finally, if we move the `p1 < 0` code up, we can remove the `p1 > 1` test.

At this point, with the code reworked, it was also changed to modern C, e.g. declare function types, etc.

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-14.c](./phillipps-step-14.c) | [phillipps-step-15.c](./phillipps-step-15.c) |

## Step 16 - split functional blocks

This version splits out of the main loop the functions that decode and print a specific piece of the text. The function `print_day_preamble` prints the day preamble and the function `move_to_segment_and_decode` prints the day text. With these new functions in place, the main function now has only the logic.

```c
int f(int p1, int p2) {
    if (p1 == 2) {
        print_day_preamble(p2 - 1);
    }

    if (p1 < p2) {
        f(p1 + 1, p2);
    }

    move_to_segment_and_decode(27 - p1);

    if (p1 == 2 && p2 < 13) {
        f(2, p2 + 1);
    }
}
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-15.c](./phillipps-step-15.c) | [phillipps-step-16.c](./phillipps-step-16.c) |

## Step 17 - the final code

This version replaces the recursive calls to `f` with loops, arriving at the final code (we no longer need `f`). And now we can see the twelve days being printed.

```c
int main(int argc, char *argv[]) {
    for (int day = 1; day < 13; day++) {
        print_day_preamble(day);
        for (int i = day + 1; i >= 2; i--) {
            move_to_segment_and_decode(27 - i);
        }
    }
}
```

| Starting point                               | New code                                     |
| -------------------------------------------- | -------------------------------------------- |
| [phillipps-step-16.c](./phillipps-step-16.c) | [phillipps-step-17.c](./phillipps-step-17.c) |

## How do you know the code still works?

Good question. Before embarking on a code refactoring activity like this, we need a plan to prove that we are not changing the code's behavior. Note the carefully chosen words: we are not trying to prove that the code works. We are just ensuring that we are not changing what it does when modifying it. Proving that the code works is a different topic.

Proving that we are not modifying the behavior of the code has two parts:

1. Capture the behavior of the code before we modify it.
1. Compare the new code's behavior with the old code's behavior.

In our case, for step one we can simply save the output of the code into a file. Then, for step two we capture the output of the new code into a file and compare the two files.

The [test script](./test.sh) automates that process.
