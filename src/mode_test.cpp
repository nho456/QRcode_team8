static int8_t getAlphanumeric(char c) {

	if (c >= '0' && c <= '9') { return (c - '0'); }
	if (c >= 'A' && c <= 'Z') { return (c - 'A' + 10); }

	switch (c) {
	case ' ': return 36;
	case '$': return 37;
	case '%': return 38;
	case '*': return 39;
	case '+': return 40;
	case '-': return 41;
	case '.': return 42;
	case '/': return 43;
	case ':': return 44;
	}

	return -1;
}

static bool isAlphanumeric(const char *text, uint16_t length) {
	while (length != 0) {
		if (getAlphanumeric(text[--length]) == -1) { return false; }
	}
	return true;
}


static bool isNumeric(const char *text, uint16_t length) {
	while (length != 0) {
		char c = text[--length];
		if (c < '0' || c > '9') { return false; }
	}
	return true;
}