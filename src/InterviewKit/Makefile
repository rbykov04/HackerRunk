OUTPUT_PATH=test.taa


define testing
	cat $(1).test | ./$@
	@echo "[TEST     ] $(1)"
	@if cmp -s $(OUTPUT_PATH) $(1).etalon; \
	then echo '[    GOOD ]'; \
	else \
		 echo "MY result:"; \
		 cat $(OUTPUT_PATH); \
		 echo "\nExpected Output:"; \
		 cat $(1).etalon; \
		 echo '\n[     BAD ]'; \
	fi; 
endef


warm_repeated_string: warm_repeated_string_make
	@$(call testing,$@-1)
	@$(call testing,$@-2)


warm_repeated_string_make:
	@gcc -g -std=c++11 -Werror -Wall -pedantic warm_repeated_string.cpp -lstdc++ -o warm_repeated_string

all: say


usage:
	@echo "Hi, i am makefile"
clean:
	rm warm_repeated_string
