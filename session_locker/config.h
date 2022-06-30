/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody"; /* nogroup if not arch linux */

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#282828",   /* after initialization */
	[INPUT] =  "#a89984",   /* during input */
	[FAILED] = "#ff0000",   /* wrong password */
};

/* lock screen opacity */
static const float alpha = 0.1;

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

/* time in seconds before the monitor shuts down */
static const int monitortime = 30;

/* default message */
static const char * message = "Enter your password to unlock session.";

/* text color */
static const char * text_color = "#ffffff";

/* text size (must be a valid size) */
static const char * font_name = "LiberationSans-Regular:size=18";
