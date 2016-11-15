#ifndef WINTOOLS_H
#define WINTOOLS_H

#include <iostream>

using namespace std;

typedef enum icons {INFO, QUESTION, ERRORS, WARNING} icon;
typedef enum buttons {OK, OK_CANCEL, YES_NO, YES_NO_CANCEL, RETRY_CANCEL, ABORT_RETRY_IGNORE } button;

int mbox(const char* title, const char* body, icon type, button but);

void send_keys(string z);
void instant_send_keys(string z);
void create_process(char* name);
void change_background(string path);
void hold_down(string z, int delay);

void switch_monitor_status(int delay);
void open_cd_tray();


#endif // WINTOOLS_H
