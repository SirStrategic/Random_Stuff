//first function
std::vector<std::string> parseArgs(std::string args) {
	std::vector<std::string> seperatedArgs;
	std::string sb;
	bool was_space = false;
	bool is_space = false;
	for (int i = 0; i < args.size(); ++i) {
		if (isspace(args[i])) {
			is_space = true;
			if (i == 0) {
				was_space = is_space;
				continue;
			}
		}
		else {
			sb.push_back(args[i]);
			is_space = false;
		}
		if ((!was_space) && is_space) {
			seperatedArgs.push_back(sb);
			sb.clear();
		}
		was_space = is_space;
	}
}

//second function
char** parseArgs(const char* args) {
	char** seperatedArgs = (char**)malloc(1 * sizeof(char*));
	int sas = 1; 
	char* sb = (char*)malloc(1 * sizeof(char)); 
	int sbs = 1; //sb size
	bool was_space = false;
	bool is_space = false;
	for (int i = 0; i < strlen(args); ++i) {

		if (isspace(args[i])) {
			is_space = true;
			if (i == 0) {
				was_space = is_space;
				continue;
			}
		}
		else {
			++sbs;
			sb = (char*)realloc(sb, sbs * sizeof(char));
			int temp = sbs - 2;
			sb[sbs - 2] = args[i];
			is_space = false;
		}
		if ((!was_space) && is_space) {
			sb[sbs - 1] = '\0';
			++sas;
			seperatedArgs = (char**)realloc(seperatedArgs, sas * sizeof(char*));
			seperatedArgs[sas - 2] = sb;
			sb = (char*)malloc(1);
			sbs = 1;
		}
		was_space = is_space;
	}
	return seperatedArgs;
}
