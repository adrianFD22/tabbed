/* See LICENSE file for copyright and license details. */

/* appearance */
static char* font         = "monospace:size=8";
static char* normbgcolor  = "#222222";
static char* normfgcolor  = "#cccccc";
static char* selbgcolor   = "#555555";
static char* selfgcolor   = "#ffffff";
static char* urgbgcolor   = "#111111";
static char* urgfgcolor   = "#cc0000";
static char* before       = "<";
static char* after        = ">";
static char* titletrim    = "...";
static int tabwidth       = 50;
static int focusnew       = 1;
static int urgentswitch   = 0;
static int barHeight	  = 20;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int newposition   = -1;
static int npisrelative  = 0;

#define SETPROP(p) { \
        .v = (char *[]){ "/bin/sh", "-c", \
                "prop=\"`xwininfo -children -id $1 | grep '^     0x' |" \
                "sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' |" \
                "xargs -0 printf %b | dmenu -p \"Select:\" -l 10 -i -w $1`\" &&" \
                "xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
                p, winid, NULL \
        } \
}

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
	{ "font",         STRING,  &font},
	{ "background",  STRING,  &normbgcolor},
	{ "foreground",  STRING,  &normfgcolor},
	{ "selected.background",   STRING,  &selbgcolor},
	{ "selected.foreground",   STRING,  &selfgcolor},
	{ "urgent.background",   STRING,  &urgbgcolor},
	{ "urgent.foreground",   STRING,  &urgfgcolor},
	{ "before",       STRING,  &before},
	{ "after",        STRING,  &after},
	{ "titletrim",    STRING,  &titletrim},
	{ "tabwidth",     INTEGER, &tabwidth},
	{ "focusnew",     INTEGER, &focusnew},
	{ "urgentswitch", INTEGER, &urgentswitch},
	{ "newposition",  INTEGER, &newposition},
	{ "npisrelative", INTEGER, &npisrelative},
};

#define MODKEY Mod1Mask
static const Key keys[] = {
	/* modifier             key        function     argument */
	//{ MODKEY|ShiftMask,     XK_Return, focusonce,   { 0 } },
	//{ MODKEY|ShiftMask,     XK_Return, spawn,       { 0 } },

	{ MODKEY,               XK_l,       rotate,      { .i = +1 } },
	{ MODKEY,               XK_h,       rotate,      { .i = -1 } },
	{ MODKEY|ShiftMask,     XK_l,       movetab,     { .i = +1 } },
	{ MODKEY|ShiftMask,     XK_h,       movetab,     { .i = -1 } },
	//{ MODKEY,               XK_Tab,    rotate,      { .i = 0 } },

	{ MODKEY,               XK_f,       spawn,       SETPROP("_TABBED_SELECT_TAB") },
	//{ MODKEY,               XK_k,      move,        { .i = +1 } },
	//{ MODKEY,               XK_j,      move,        { .i = -1 } },
	//{ MODKEY,               XK_2,      move,        { .i = 1 } },
	//{ MODKEY,               XK_3,      move,        { .i = 2 } },
	//{ MODKEY,               XK_4,      move,        { .i = 3 } },
	//{ MODKEY,               XK_5,      move,        { .i = 4 } },
	//{ MODKEY,               XK_6,      move,        { .i = 5 } },
	//{ MODKEY,               XK_7,      move,        { .i = 6 } },
	//{ MODKEY,               XK_8,      move,        { .i = 7 } },
	//{ MODKEY,               XK_9,      move,        { .i = 8 } },
	//{ MODKEY,               XK_0,      move,        { .i = 9 } },

	//{ MODKEY,               XK_q,      killclient,  { 0 } },

	//{ MODKEY,               XK_u,      focusurgent, { 0 } },
	//{ MODKEY|ShiftMask,     XK_u,      toggle,      { .v = (void*) &urgentswitch } },

	//{ 0,                    XK_F11,    fullscreen,  { 0 } },
};
