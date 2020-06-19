#include "sockClient.h"
#include <iostream>
#include <cstdio>
#include <string>

int main() {
	sockClient *sc = new sockClient();
	std::string tmp = "hehe";
	int control;
	//must do check()
	sc->check();
	while (1) {
		printf("Please type in a number to test sending message (0: wind, 1: ebc, 2: ettoday)\n> ");
		scanf("%d", &control);
		switch(control) {
			// send_xxx(status: 1: success 0: fail, news_type: 0: wind 1:ebc 2:ettoday, url string)
			case 0:
				sc->send_message(0, 0, tmp);
				break;
			case 1:
				sc->send_message(0, 1, tmp);
				break;
			case 2:
				sc->send_message(0, 2, tmp);
				break;
			default:
				return 0;
		}
	}
	return 0;
}
