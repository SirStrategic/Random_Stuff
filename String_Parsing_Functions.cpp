//first function
std::vector<std::string> parseArgs(std::string args) {
	std::vector<std::string> seperatedArgs;
	std::string sb;
	bool was_space = false;
	bool is_space = false;
	for (int i = 0; i < args.size(); ++i) {
		if (isspace(args[i])) {
			is_space = true;
			//hopefully the compiler optimises this
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
		//probably the most efficient way
		was_space = is_space;
	}
}

//second function
char** parseArgs(const char* args) {
	char** seperatedArgs = (char**)malloc(1 * sizeof(char*));
	int sas = 1; //seperatedArgs size
	char* sb = (char*)malloc(1 * sizeof(char)); //String Builder 
	int sbs = 1; //sb size
	bool was_space = false;
	bool is_space = false;
	for (int i = 0; i < strlen(args); ++i) {
	//check if space, if previous wasn't then push string abck

		if (isspace(args[i])) {
			is_space = true;
			//hopefully the compiler optimises this
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
			//null terminate
			sb[sbs - 1] = '\0';
			//erm
			++sas;
			seperatedArgs = (char**)realloc(seperatedArgs, sas * sizeof(char*));
			seperatedArgs[sas - 2] = sb;
			//now pointer has been transfored to seperatedArgs I can reassign
			sb = (char*)malloc(1);
			sbs = 1;
		}
		//probably the most efficient way
		was_space = is_space;
	}
	return seperatedArgs;
}
