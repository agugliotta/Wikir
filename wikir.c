# Copyright (C) 2012 Agustin Gugliotta
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
#
# Author:
# Agustin Gugliotta agustin.mdq.89 () gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char command[100];
int i=0;
int firstWordLen = 0;
int WordLen = 0;

int main(int argc, char *argv[])
{

// Avoid accessing the array if there is no char on it.
if (argv[1] != NULL ) {

	strncat(command, "dig +short txt ",15);

	// Avoid putting too much data on those buffers!!
	firstWordLen = strlen(argv[1]);
	if (firstWordLen > 0 && firstWordLen < 50) {
		strncat(command,argv[1],firstWordLen);
	}
	else {
		printf("Sorry, word length must be less than 50 chars and more than 0.\n");
		exit(-1);
	}

	// If the input has more than two words, just concatenate them using _
	for (i = 2; i < argc; i++) {
		strncat(command,"_",1);

		// Avoid putting too much data on those buffers!!
		WordLen = strlen(argv[i]);
		if (WordLen > 0 && WordLen < 50) {
			strncat(command,argv[i],WordLen);
		}
		else {
			printf("Sorry, word length must be less than 50 chars.\n");
			exit(-1);
		}
	}

	strncat(command,".wp.dg.cx",9);
	system(command);
}

}
