#ifndef HOME_DIR
    #define HOME_DIR "/home/zulibit"  // Default fallback
#endif

/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const unsigned int borderpx         = 1;  /* border pixel of windows */
static const int showbar                   = 1; /* 0 means no bar */
static const int topbar                    = 1; /* 0 means bottom bar */
static const int smartgaps                 = 0;  /* 1 means no outer gap when there is only one window */
static int gaps                            = 1;  /* 1 means gaps between windows are added */
static const unsigned int gappx            = 10; /* gap pixel between windows */
static const int vertpad                   = 0; /* vertical padding of bar */
static const int sidepad                   = 0; /* horizontal padding of bar */
static const char *fonts[]                 = {"Hack Nerd Font Mono:size=16"};
static const float rootcolor[]             = COLOR(0x000000ff);
/* Fullscreen background (Nord Color) */
static const float fullscreen_bg[]         = { 0.16f, 0.20f, 0.24f, 1.0f }; /* Nord0 with slight transparency */
/* Color Scheme */
static uint32_t colors[][3] = {
    /*               fg          bg              border    */
    [SchemeNorm] = { 0x5e81acff, 0x3b4252d9, 0x3b4252ff },  /* Light gray foreground, Nord1 background with 70% opacity, Nord1 border */
    [SchemeSel]  = { 0xffffffff, 0x3b4252d9, 0x5e81acff },  /* Light blue foreground, Nord1 background with 70% opacity, Dark blue border */
    [SchemeUrg]  = { 0x2e3440ff, 0xbf616ad9, 0xbf616aff },  /* Dark background, Red foreground, Red border with 70% opacity */
};

/* tagging - TAGCOUNT must be no greater than 31 */
static char *tags[] = { "󰻽", "", "󰈹", "", "󰭹"};

/* logging */
static int log_level = WLR_ERROR;

/* Autostart */
static const char *const autostart[] = {
    "swaybg", "-i", HOME_DIR "/icede/wallpaper/bg4.jpg", "-m", "fill", NULL,
    "pipewire", NULL,
    "wireplumber", NULL,
    "mako",
    "--background-color", "#2e3440",      // Nord 0 (dark background)
    "--text-color", "#d8dee9",            // Nord 4 (light text)
    "--border-color", "#3b4252",          // Nord 1 (dark border)
    "--border-size", "2",                 // Optional border size
    "--font", "Hack Nerd Font Mono 12",   // Set font to Noto Sans (or another font of your choice)
    "--icons", "1",                       // Enable icons
    "--max-icon-size", "64",              // Max icon size in px
    NULL /* terminate */
};

/* NOTE: ALWAYS keep a rule declared even if you don't use rules (e.g leave at least one example) */
static const Rule rules[] = {
	/* app_id             title       tags mask     isfloating   monitor */
	/* examples: */
	{ "firefox_EXAMPLE",  NULL,       1 << 8,       0,           -1 }, /* Start on ONLY tag "9" */
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle }, 
};

/* monitors */
/* (x=-1, y=-1) is reserved as an "autoconfigure" monitor position indicator
 * WARNING: negative values other than (-1, -1) cause problems with Xwayland clients
 * https://gitlab.freedesktop.org/xorg/xserver/-/issues/899
*/
/* NOTE: ALWAYS add a fallback rule, even if you are completely sure it won't be used */
static const MonitorRule monrules[] = {
	/* name       mfact  nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor: */
	{ "eDP-1",    0.5f,  1,      1.2,  &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	
	/* defaults */
	{ NULL,       0.55f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	.options = "ctrl:nocaps",
	*/
	.options = NULL,
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;

/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_LOGO

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,SKEY,toggletag, {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[] = { "foot", "-c", HOME_DIR "/icede/foot.ini", NULL };
static const char *menucmd[] = { "fuzzel", "--config", HOME_DIR "/icede/fuzzel.ini", NULL };
static const char *swaylockcmd[] = {
    "swaylock",
    "--color", "2e3440f8",        /* Background color with transparency (f8 = 97% opaque) */
    "--ring-color", "5e81ac",     /* Ring color (Light blue) */
    "--text-color", "ffffff",     /* Text color (White) */
    NULL
};
static const char *toggle_waybar[] = {"/bin/sh", "-c", "pkill waybar || waybar -c " HOME_DIR "/icede/waybar/config -s " HOME_DIR "/icede/waybar/style.css", NULL };
static const char *upvol[] = { "/usr/bin/pamixer", "-i", "10", "--set-limit", "120", NULL };
static const char *downvol[] = { "/usr/bin/pamixer", "-d", "10", "--set-limit", "120", NULL };
static const char *mutevol[] = { "/usr/bin/pamixer", "--toggle-mute", NULL };
static const char *light_up[] = {"/usr/bin/light", "-A", "5", NULL};
static const char *light_down[] = {"/usr/bin/light", "-U", "5", NULL};
static const char *mutemic[] = { "/usr/bin/pactl", "set-source-mute", "@DEFAULT_SOURCE@", "toggle", NULL };
/* For this to work ~/Pictures must exists */
static const char *screenshotcmd[] = { 
    "/bin/sh", "-c", 
    "mkdir -p ~/Pictures && grim -g \"$(slurp)\" - | swappy -f - -o ~/Pictures/edited-$(date +%Y%m%d%H%M%S).png", 
    NULL 
};

static const char *recordcmd[] = { 
    "foot", "-e", 
    "sh", "-c", 
    "wf-recorder -g \"$(slurp)\" -f ~/Pictures/recording-$(date +%Y%m%d%H%M%S).mp4", 
    NULL 
};


static const Key keys[] = {
    {0, XKB_KEY_XF86AudioLowerVolume, spawn, {.v = downvol}},    // Use XKB_KEY_XF86AudioLowerVolume
    {0, XKB_KEY_XF86AudioMute, spawn, {.v = mutevol}},            // Use XKB_KEY_XF86AudioMute
    {0, XKB_KEY_XF86AudioRaiseVolume, spawn, {.v = upvol}},       // Use XKB_KEY_XF86AudioRaiseVolume
    {0, XKB_KEY_XF86MonBrightnessUp, spawn, {.v = light_up}},     // Use XKB_KEY_XF86MonBrightnessUp
    {0, XKB_KEY_XF86MonBrightnessDown, spawn, {.v = light_down}}, // Use XKB_KEY_XF86MonBrightnessDown
    {0, XKB_KEY_XF86AudioMicMute, spawn, {.v = mutemic}},           // Use XKB_KEY_XF86AudioMicMute
	/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
	/* modifier                  key                 function        argument */
	{ MODKEY,                    XKB_KEY_p,          spawn,          {.v = menucmd} },
	{ MODKEY,                    XKB_KEY_Return,     spawn,          {.v = termcmd} },
	{ MODKEY,                    XKB_KEY_o,     	 spawn,          {.v = toggle_waybar} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_BackSpace,  spawn,          {.v = swaylockcmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_S,     	 spawn,          {.v = recordcmd} },
	{ MODKEY,                    XKB_KEY_s,     	 spawn,          {.v = screenshotcmd} },
	{ MODKEY,                    XKB_KEY_b,          togglebar,      {0} },
	{ MODKEY,                    XKB_KEY_j,          focusstack,     {.i = +1} },
	{ MODKEY,                    XKB_KEY_k,          focusstack,     {.i = -1} },
	{ MODKEY,                    XKB_KEY_i,          incnmaster,     {.i = +1} },
	{ MODKEY,                    XKB_KEY_d,          incnmaster,     {.i = -1} },
	{ MODKEY,                    XKB_KEY_h,          setmfact,       {.f = -0.05f} },
	{ MODKEY,                    XKB_KEY_l,          setmfact,       {.f = +0.05f} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_H,          setcfact,       {.f = +0.25f} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_L,          setcfact,       {.f = -0.25f} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_K,          setcfact,       {.f = 0.0f} },
	{ MODKEY,                    XKB_KEY_z,          zoom,           {0} },
	{ MODKEY,                    XKB_KEY_Tab,        view,           {0} },
	{ MODKEY,                    XKB_KEY_g,          togglegaps,     {0} },
	{ MODKEY,                    XKB_KEY_q,          killclient,     {0} },
	{ MODKEY,                    XKB_KEY_t,          setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                    XKB_KEY_f,          setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                    XKB_KEY_m,          setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                    XKB_KEY_space,      setlayout,      {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_space,      togglefloating, {0} },
	{ MODKEY,                    XKB_KEY_e,         togglefullscreen, {0} },
	{ MODKEY,                    XKB_KEY_0,          view,           {.ui = ~0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_parenright, tag,            {.ui = ~0} },
	{ MODKEY,                    XKB_KEY_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY,                    XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },
	TAGKEYS(          XKB_KEY_1, XKB_KEY_exclam,                     0),
	TAGKEYS(          XKB_KEY_2, XKB_KEY_at,                         1),
	TAGKEYS(          XKB_KEY_3, XKB_KEY_numbersign,                 2),
	TAGKEYS(          XKB_KEY_4, XKB_KEY_dollar,                     3),
	TAGKEYS(          XKB_KEY_5, XKB_KEY_percent,                    4),
	TAGKEYS(          XKB_KEY_6, XKB_KEY_asciicircum,                5),
	TAGKEYS(          XKB_KEY_7, XKB_KEY_ampersand,                  6),
	TAGKEYS(          XKB_KEY_8, XKB_KEY_asterisk,                   7),
	TAGKEYS(          XKB_KEY_9, XKB_KEY_parenleft,                  8),
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_E,          quit,           {0} },

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_Terminate_Server, quit, {0} },
	/* Ctrl-Alt-Fx is used to switch to another VT, if you don't know what a VT is
	 * do not remove them.
	 */
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ ClkLtSymbol, 0,      BTN_LEFT,   setlayout,      {.v = &layouts[0]} },
	{ ClkLtSymbol, 0,      BTN_RIGHT,  setlayout,      {.v = &layouts[2]} },
	{ ClkTitle,    0,      BTN_MIDDLE, zoom,           {0} },
	{ ClkStatus,   0,      BTN_MIDDLE, spawn,          {.v = termcmd} },
	{ ClkClient,   MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ ClkClient,   MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ ClkClient,   MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
	{ ClkTagBar,   0,      BTN_LEFT,   view,           {0} },
	{ ClkTagBar,   0,      BTN_RIGHT,  toggleview,     {0} },
	{ ClkTagBar,   MODKEY, BTN_LEFT,   tag,            {0} },
	{ ClkTagBar,   MODKEY, BTN_RIGHT,  toggletag,      {0} },
};
