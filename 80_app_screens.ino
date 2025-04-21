// ---------------------------- Define windows + controls. --------------------------
// *** background frame ***
struct windw_s wnd_frame;



// *** wifi networks screen ***
struct list_s lst_nets;

struct tab_ctrl_s tab_ctrl_frame = 
      { ctrl_windw, &wnd_frame, };

struct tab_ctrl_s tab_ctrl_nets = 
      { ctrl_list, &lst_nets, };

struct tab_ctrl_s tab_ctrl_none = 
      { ctrl_type_none,  NULL, };

struct tab_ctrl_s *ctrls_wifi[] =
  {
    &tab_ctrl_frame,
    &tab_ctrl_nets,
    &tab_ctrl_none,
  };

struct ctrl_screen_s wifi_screen = {
  ctrls_wifi,
  1, // focus_idx: ctrl_nets
};


// *** wifi password screen ***
struct windw_s wnd_plain;
struct label_s lbl_instr;
struct label_s lbl_net;
struct edit_s edit_pass;
struct button_s btn_ok_pass;
struct button_s btn_back;

struct tab_ctrl_s tab_ctrl_plain = 
      { ctrl_windw, &wnd_plain, };

struct tab_ctrl_s tab_ctrl_instr = 
      { ctrl_label, &lbl_instr, };

struct tab_ctrl_s tab_ctrl_net = 
      { ctrl_label, &lbl_net, };

struct tab_ctrl_s tab_ctrl_pass = 
      { ctrl_edit, &edit_pass, };

struct tab_ctrl_s tab_ctrl_ok_pass = 
      { ctrl_button, &btn_ok_pass, };

struct tab_ctrl_s tab_ctrl_back = 
      { ctrl_button, &btn_back, };

struct tab_ctrl_s *ctrls_pass[] =
  {
    &tab_ctrl_plain,
    &tab_ctrl_instr,
    &tab_ctrl_net,
    &tab_ctrl_pass,
    &tab_ctrl_ok_pass,
    &tab_ctrl_back,
    &tab_ctrl_none,
  };
  
struct ctrl_screen_s pass_screen = {
  ctrls_pass,
  3, // focus_idx: ctrl_pass
};

// *** offset screen ***
struct label_s lbl_hdr_offset;

struct label_s lbl_utc;
struct up_down_s updn_tzone;
struct check_box_s cb_daylight;

struct label_s lbl_gpsleap;
struct up_down_s updn_leapsec;

struct button_s btn_ok_offs;


struct tab_ctrl_s tab_ctrl_hdr_offset = 
      { ctrl_label, &lbl_hdr_offset, };


struct tab_ctrl_s tab_ctrl_utc = 
      { ctrl_label, &lbl_utc, };

struct tab_ctrl_s tab_ctrl_tzone = 
      { ctrl_up_down, &updn_tzone, };

struct tab_ctrl_s tab_ctrl_daylight = 
      { ctrl_check_box, &cb_daylight, };


struct tab_ctrl_s tab_ctrl_gpsleap = 
      { ctrl_label, &lbl_gpsleap, };

struct tab_ctrl_s tab_ctrl_leapsec = 
      { ctrl_up_down, &updn_leapsec, };


struct tab_ctrl_s tab_ctrl_ok_offs = 
      { ctrl_button, &btn_ok_offs, };


struct tab_ctrl_s *ctrls_offset[] =
  {
    &tab_ctrl_plain,
    &tab_ctrl_hdr_offset,

    &tab_ctrl_utc,
    &tab_ctrl_tzone,
    &tab_ctrl_daylight,

    &tab_ctrl_gpsleap,
    &tab_ctrl_leapsec,

    &tab_ctrl_ok_offs,
    &tab_ctrl_none, // end of list
  };

struct ctrl_screen_s offs_screen = {
  ctrls_offset,
  7, // focus_idx: btn_ok_offs
};


// *** display screen ***
struct label_s lbl_hdr_display;

struct label_s lbl_brightness;
struct up_down_s updn_bright;

struct button_s btn_ok_disp;


struct tab_ctrl_s tab_ctrl_hdr_display = 
      { ctrl_label, &lbl_hdr_display, };


struct tab_ctrl_s tab_ctrl_brightness = 
      { ctrl_label, &lbl_brightness, };

struct tab_ctrl_s tab_ctrl_bright = 
      { ctrl_up_down, &updn_bright, };


struct tab_ctrl_s tab_ctrl_ok_disp = 
      { ctrl_button, &btn_ok_disp, };


struct tab_ctrl_s *ctrls_display[] =
  {
    &tab_ctrl_plain,
    &tab_ctrl_hdr_display,

    &tab_ctrl_brightness,
    &tab_ctrl_bright,

    &tab_ctrl_ok_disp,
    &tab_ctrl_none, // end of list
  };

struct ctrl_screen_s disp_screen = {
  ctrls_display,
  4, // focus_idx: btn_ok_disp
};


// *** FM screen ***
struct label_s lbl_hdr_fm;

struct check_box_s cb_tx_enab;

struct up_down_s updn_freq;

struct label_s lbl_station;
struct edit_s edit_rds_station;

struct label_s lbl_message;
struct edit_s edit_rds_message;

struct button_s btn_ok_fm;

struct tab_ctrl_s tab_ctrl_hdr_fm = 
      { ctrl_label, &lbl_hdr_fm, };


struct tab_ctrl_s tab_ctrl_tx_enab = 
      { ctrl_check_box, &cb_tx_enab, };


struct tab_ctrl_s tab_ctrl_freq = 
      { ctrl_up_down, &updn_freq, };


struct tab_ctrl_s tab_ctrl_station = 
      { ctrl_label, &lbl_station, };

struct tab_ctrl_s tab_ctrl_rds_station = 
      { ctrl_edit, &edit_rds_station, };


struct tab_ctrl_s tab_ctrl_message = 
      { ctrl_label, &lbl_message, };

struct tab_ctrl_s tab_ctrl_rds_message = 
      { ctrl_edit, &edit_rds_message, };


struct tab_ctrl_s tab_ctrl_ok_fm = 
      { ctrl_button, &btn_ok_fm, };


struct tab_ctrl_s *ctrls_fm[] =
  {
    &tab_ctrl_plain,
    &tab_ctrl_hdr_fm,

    &tab_ctrl_tx_enab,

    &tab_ctrl_freq,

    &tab_ctrl_station,
    &tab_ctrl_rds_station,

    &tab_ctrl_message,
    &tab_ctrl_rds_message,

    &tab_ctrl_ok_fm,
    &tab_ctrl_none, // end of list
  };

struct ctrl_screen_s fm_screen = {
  ctrls_fm,
  8, // focus_idx: btn_ok_fm
};

// *** main app screen ***
struct label_s lbl_clock;
struct button_s btn_ip;
struct button_s btn_display;
struct button_s btn_offset;
struct button_s btn_fm;

struct tab_ctrl_s tab_ctrl_clock = 
      { ctrl_label, &lbl_clock, };


struct tab_ctrl_s tab_ctrl_ip = 
      { ctrl_button, &btn_ip, };

struct tab_ctrl_s tab_ctrl_display = 
      { ctrl_button, &btn_display, };

struct tab_ctrl_s tab_ctrl_offset = 
      { ctrl_button, &btn_offset, };

struct tab_ctrl_s tab_ctrl_fm = 
      { ctrl_button, &btn_fm, };


struct tab_ctrl_s *ctrls_app[] =
  {
    &tab_ctrl_plain,
    &tab_ctrl_clock,

    &tab_ctrl_ip,
    &tab_ctrl_display,
    &tab_ctrl_offset,
    &tab_ctrl_fm,

    &tab_ctrl_none, // end of list
  };
  
struct ctrl_screen_s app_screen = {
  ctrls_app,
  1, // focus_idx: ctrl_ip
};

// *** initial screen at start ***
//struct ctrl_screen_s *cur_screen = &wifi_screen;
//struct ctrl_screen_s *cur_screen = &pass_screen;
//struct ctrl_screen_s *cur_screen = &disp_screen;
struct ctrl_screen_s *cur_screen = &app_screen;

// ---------------------------- Set up screen controls -----------------------------------
void setup_app_screens(void) {
  // *** WiFi screen *** - setup elements
  SetupWindow (&wnd_frame, /*x0*/0, /*y0*/0, tft.width()-1, tft.height()-1, /*border*/1, /*buffered*/0);
#ifdef HX8357
  SetupList (&lst_nets, /*x*/20, /*y*/12, /*text_max_chars*/20, /*visible_count*/10, /*void cb_func(char *)*/&list_selected, /*item_prefix*/NULL);//"WiFi");
#endif

  // *** Password screen *** - setup elements
  SetupWindow (&wnd_plain, /*x0*/0, /*y0*/0, tft.width(), tft.height()-1, /*border*/0, /*buffered*/0);
  SetupLabel (&lbl_instr, /*x*/1, /*y*/1, /*max_chars*/19, /*text_default*/"Enter password for:");
  SetupLabel (&lbl_net, /*x*/1, /*y*/1+LABEL_HEIGHT_PIXELS+1, /*max_chars*/16, /*text_default*/"Default WiFi Name");
  SetupEdit (&edit_pass, /*x*/1, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1, /*text_max_chars*/16, "Doyourwork!22");
  SetupButton (&btn_ok_pass, /*x*/80, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1+EDIT_HEIGHT_PIXELS+3, "OK", /*void cb_func(void)*/&cb_passwd_ok_clicked);
  SetupButton (&btn_back, /*x*/1, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1+EDIT_HEIGHT_PIXELS+3, "Back", /*void cb_func(void)*/&cb_passwd_back_clicked);


  // *** Offset screen *** - setup elements

  //  title
  SetupLabel (&lbl_hdr_offset, /*x*/tft.width()/2-(6*CHAR_WIDTH_PIXELS)/2, /*y*/1, /*max_chars*/7, /*text_default*/"Offset");

  //  UTC offset
  SetupLabel (&lbl_utc, /*x*/1, /*y*/36, /*max_chars*/3, /*text_default*/"UTC");
  SetupUpDown (&updn_tzone, /*x*/60, /*y*/36, /*text_max_chars*/5, &cb_offs_tzone_set/*void cb_func(double sel_val)*/, NULL/*void cb_chg_func(double chg_val)*/, /*min_val*/-12, /*max_val*/+14, /*dfl_val*/-6, /*val_step*/0.5, /*val_prec*/1);

  //  DST check
  SetupCheckBox (&cb_daylight, /*x*/165, /*y*/36, /*text_str*/"DST", 1/*checked_default*/, &cb_offs_dst_set/*void cb_func(int check_val)*/);

  //  Leap sec
  SetupLabel (&lbl_gpsleap, /*x*/1, /*y*/69, /*max_chars*/10, /*text_default*/"Leap sec");
  SetupUpDown (&updn_leapsec, /*x*/140, /*y*/69, /*text_max_chars*/3, NULL/*void cb_func(double sel_val)*/, &cb_offs_leapsec_set/*void cb_chg_func(double chg_val)*/, /*min_val*/-59, /*max_val*/+59, /*dfl_val*/18, /*val_step*/1, /*val_prec*/0);

  SetupButton (&btn_ok_offs, /*x*/80, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1+EDIT_HEIGHT_PIXELS+3, "OK", /*void cb_func(void)*/&cb_offs_ok_clicked);

  // *** Display screen *** - setup elements

  //  title
  SetupLabel (&lbl_hdr_display, /*x*/tft.width()/2-(7*CHAR_WIDTH_PIXELS)/2, /*y*/1, /*max_chars*/7, /*text_default*/"Display");

  //  Brightness
  SetupLabel (&lbl_brightness, /*x*/1, /*y*/69, /*max_chars*/10, /*text_default*/"Brightness");
  SetupUpDown (&updn_bright, /*x*/160, /*y*/69, /*text_max_chars*/2, NULL/*void cb_func(double sel_val)*/, &cb_disp_bright_set/*void cb_chg_func(double chg_val)*/, /*min_val*/-1, /*max_val*/0, /*dfl_val*/0, /*val_step*/1, /*val_prec*/0);

  // OK
  SetupButton (&btn_ok_disp, /*x*/80, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1+EDIT_HEIGHT_PIXELS+3, "OK", /*void cb_func(void)*/&cb_disp_ok_clicked);


  // *** FM screen *** - setup elements

  //  title
  SetupLabel (&lbl_hdr_fm, /*x*/tft.width()/2-(2*CHAR_WIDTH_PIXELS)/2, /*y*/1, /*max_chars*/3, /*text_default*/"FM");

  //  Transmit Enable: tx_enab
  //SetupLabel (&lbl_mhz, /*x*/1, /*y*/36, /*max_chars*/19, /*text_default*/"starting FM ...");
  SetupCheckBox (&cb_tx_enab, /*x*/1, /*y*/36, /*text_str*/"TX", 1/*checked_default*/, &cb_fm_tx_enab_set/*void cb_func(int check_val)*/);

  //  freq
  SetupUpDown (&updn_freq, /*x*/60, /*y*/36, /*text_max_chars*/5, NULL/*void cb_func(double sel_val)*/, &cb_fm_freq_set/*void cb_chg_func(double chg_val)*/, /*min_val*/87.5, /*max_val*/108.0, /*dfl_val*/102.3, /*val_step*/0.1, /*val_prec*/1);

  //  station
  SetupLabel (&lbl_station, /*x*/1, /*y*/69, /*max_chars*/7, /*text_default*/"Station");
  SetupEdit (&edit_rds_station, /*x*/104, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1, /*text_max_chars*/FM_RDS_STATION_MAX, "AdaRadio");

  //  message
  SetupLabel (&lbl_message, /*x*/1, /*y*/102, /*max_chars*/8, /*text_default*/"Message");
  SetupEdit (&edit_rds_message, /*x*/1, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1, /*text_max_chars*/FM_RDS_MESSAGE_MAX, "Adafruit g0th Radio!");

  // OK
  SetupButton (&btn_ok_fm, /*x*/140, /*y*/1+LABEL_HEIGHT_PIXELS+1+LABEL_HEIGHT_PIXELS+1+EDIT_HEIGHT_PIXELS+1+EDIT_HEIGHT_PIXELS+1+EDIT_HEIGHT_PIXELS+3, "OK", /*void cb_func(void)*/&cb_fm_ok_clicked);

  // *** App screen *** - setup elements

  //  title
  SetupLabel (&lbl_clock, /*x*/tft.width()/2-(5*CHAR_WIDTH_PIXELS)/2, /*y*/1, /*max_chars*/5, /*text_default*/"Radio");

  //  WiFi IP / NO Wifi button
  SetupButton (&btn_ip, /*x horiz*/24, /*y vert*/36, "000.000.000.000", /*void cb_func(void)*/&cb_app_ip_clicked); // force button to be big enough for full IP

  //  Display button
  SetupButton (&btn_display, /*x horiz*/24, /*y vert*/69, "Display", /*void cb_func(void)*/&cb_app_display_clicked);

  //  Offset button
  SetupButton (&btn_offset, /*x horiz*/130, /*y vert*/69, "Offset", /*void cb_func(void)*/&cb_app_offset_clicked);

  //  FM status / No FM button
  SetupButton (&btn_fm, /*x*/24, /*y*/102, "starting FM", /*void cb_func(void)*/&cb_app_fm_clicked); // force button to be big enough for text

  app_settings_get (app_settings);
  SetCheckBox (&cb_tx_enab, app_settings->tx_enab);
  SetUpDown   (&updn_freq,  app_settings->freq);
  SetEdit     (&edit_rds_station,   app_settings->rds_station);
  SetEdit     (&edit_rds_message,   app_settings->rds_message);

  SetUpDown   (&updn_tzone,  app_settings->gmt_offset_hours);
  SetCheckBox (&cb_daylight, app_settings->daylight_observed);
  SetUpDown   (&updn_leapsec,  app_settings->leap_sec);

  SetUpDown   (&updn_bright,  app_settings->bright_steps);
  ScreenDraw();
}
// ---------------------------- Manage list -----------------------------------
// set an item in the list
void set_list_item (int item_idx, const char *new_fmt, ...) {
  char new_text[LIST_MAX_TEXT];

  va_list args;
  va_start (args, new_fmt);
  vsnprintf (new_text, LIST_MAX_TEXT, new_fmt, args);
  va_end (args);

  SetListItem (&lst_nets, item_idx, new_text);
}

// add an item to the list
//  if it already exists, nothing will be added.
void add_list_item (const char *new_fmt, ...) {
  char new_text[LIST_MAX_TEXT];

  va_list args;
  va_start (args, new_fmt);
  vsnprintf (new_text, LIST_MAX_TEXT, new_fmt, args);
  va_end (args);

  AddListItem (&lst_nets, new_text);
}

// redraw the list
//  Call this after done setting/adding items.
void redraw_list (void) {
  if (lst_nets.needs_redraw) { // need to redraw the list of wifi networks (b/c we added 1 or more networks)
    ScreenRedrawCtrl(&tab_ctrl_nets);
  }
}

void list_selected(char *sel_net) {
  // Accept WiFi network
//  strncpy (app_settings->ssid, sel_net, APP_SETTINGS_STR_MAX);
  // setup control on next screen with WiFi network name.
  set_net_label (sel_net);

  // Change to password screen.
  cur_screen = &pass_screen;
  ScreenDraw();
}

bool current_screen_is_wifi(void) {
  if (cur_screen == &wifi_screen) {
    return true; // we are looking at the screen that shows the wifi networks
  }
  return false;
}
// ---------------------------- WiFi Password Screen functions --------------------------
// Set WiFi Network label
void set_net_label (char *new_fmt, ...) {
  char new_text[LABEL_MAX_TEXT];
  va_list args;

  va_start (args, new_fmt);
  vsnprintf (new_text, LABEL_MAX_TEXT, new_fmt, args);
  va_end (args);

  SetLabel (&lbl_net, new_text);
}

void cb_passwd_back_clicked (void) {
  // Change back to WiFi (network selection) screen.
  cur_screen = &wifi_screen;
  ScreenDraw();
}

void cb_passwd_ok_clicked (void) {
  char *password;

  // Accept WiFi password.
  password = GetEdit(&edit_pass);
//  strncpy (app_settings->password, password, APP_SETTINGS_STR_MAX);

  // Go to main app screen.
  cur_screen = &app_screen;
  ScreenDraw();
}
// ---------------------------- Offset Screen functions --------------------------
void cb_offs_tzone_set (double tzone_hrs) {
 app_settings->gmt_offset_hours = tzone_hrs; 
 app_settings_put (app_settings);
}

void cb_offs_dst_set (int dst_checked) {
 app_settings->daylight_observed = dst_checked; 
 app_settings_put (app_settings);
}

void cb_offs_leapsec_set (double leapsec_in) {
 app_settings->leap_sec = leapsec_in; 
 app_settings_put (app_settings);
}

void cb_offs_ok_clicked (void) {
  // Go to main app screen.
  cur_screen = &app_screen;
  ScreenDraw();
}
// ---------------------------- Display Screen functions --------------------------

void cb_disp_bright_set (double bright_steps) {
 app_settings->bright_steps = bright_steps; 
 app_settings_put (app_settings);
 //sevenseg_bright_set ();
}

void cb_disp_ok_clicked (void) {
  // Go to main app screen.
  cur_screen = &app_screen;
  ScreenDraw();
}
// ---------------------------- FM Screen functions --------------------------
#if 0
// Set label on this screen.
// If this screen is showing, and the text changed,
//  then draw the label.
void set_fm_v_label (struct label_s *lbl, const char *new_fmt, va_list args) {
  char new_text[LABEL_MAX_TEXT];
  bool chg;

  vsnprintf (new_text, LABEL_MAX_TEXT, new_fmt, args);

  chg = SetLabel (lbl, new_text);
  //ScreenDraw();
  if (chg && current_screen_is_fm()) {
    DrawLabel (lbl, false/*!has_focus*/);
  }
}

// Set FN Freq label
void set_fm_freq_label (const char *new_fmt, ...) {
  va_list args;
  va_start (args, new_fmt);
  set_fm_v_label (&lbl_freq, new_fmt, args);
  va_end (args);
}
#endif

bool current_screen_is_fm(void) {
  if (cur_screen == &fm_screen) {
    return true; // we are looking at the screen that shows the GPS details
  }
  return false;
}

void cb_fm_tx_enab_set(int check_val) {
  app_settings->tx_enab = check_val;
}

void cb_fm_freq_set(double chg_val) {
  app_settings->freq = chg_val;
}

void cb_fm_ok_clicked (void) {
  char *rds_station;
  char *rds_message;

  // Accept station and message.
  rds_station = GetEdit(&edit_rds_station);
  strncpy (app_settings->rds_station, rds_station, APP_SETTINGS_STR_MAX);

  rds_message = GetEdit(&edit_rds_message);
  strncpy (app_settings->rds_message, rds_message, APP_SETTINGS_STR_MAX);

  // Go to main app screen.
  cur_screen = &app_screen;
  ScreenDraw();
}
// ---------------------------- Main App Screen functions --------------------------
// Set text on IP Address button
void set_ip_btn (const char *new_fmt, ...) {
  char new_text[BUTTON_MAX_LABEL];

  va_list args;
  va_start (args, new_fmt);
  vsnprintf (new_text, BUTTON_MAX_LABEL, new_fmt, args);
  va_end (args);

  SetButtonText (&btn_ip, new_text);
  ScreenRedrawCtrl(&tab_ctrl_ip);
}

bool current_screen_is_app(void) {
  if (cur_screen == &app_screen) {
    return true; // we are looking at the screen that shows the main app controls
  }
  return false;
}

void app_update(void) {
  if (!fm_found) {
    set_app_fm_btn("NO FM");
  } else if (!app_settings->tx_enab) {
    set_app_fm_btn("FM Off");
  } else {
    set_app_fm_btn("FM %.1f", app_settings->freq);
  }
}

void cb_app_ip_clicked (void) {
  // Change back to WiFi (network selection) screen.
  cur_screen = &wifi_screen;
  ScreenDraw();
}

void cb_app_offset_clicked (void) {
  // Change to Offset screen.
  cur_screen = &offs_screen;
  ScreenDraw();
}

void cb_app_display_clicked (void) {
  // Change to Display screen.
  cur_screen = &disp_screen;
  ScreenDraw();
}

void cb_app_fm_clicked (void) {
  // Change to FM screen.
  cur_screen = &fm_screen;
  ScreenDraw();
}

// Set text on FM button
void set_app_fm_btn (const char *new_fmt, ...) {
  char new_text[BUTTON_MAX_LABEL];
  bool chg;

  va_list args;
  va_start (args, new_fmt);
  vsnprintf (new_text, BUTTON_MAX_LABEL, new_fmt, args);
  va_end (args);

  chg = SetButtonText (&btn_fm, new_text);
  //ScreenDraw();
  if (chg && current_screen_is_app()) {
    ScreenRedrawCtrl (&tab_ctrl_fm);
  }
}