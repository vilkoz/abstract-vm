ifeq ($(shell uname -s),Linux)
	NO_COLOR="\033[0m"
	OK_COLOR="\033[0;32m"
	ERROR_COLOR="\033[0;31m"
else
	NO_COLOR="\x1b[0m"
	OK_COLOR="\x1b[32;01m"
	ERROR_COLOR="\x1b[31;01m"
endif

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)

VPATH = avm/

TESTS = 01_test.avm		\
		02_test.avm		\
		03_test.avm

REAL_TESTS = $(TESTS)

OUT_DIR = out/

OUTS = $(addprefix $(OUT_DIR), $(REAL_TESTS:.avm=.txt))

EXPECTED_DIR = expected/

all: $(OUTS)

$(OUT_DIR)%.txt: %.avm
	@mkdir -p $(shell dirname $@)
	@../avm $< > $@
	@echo -n "$<: "
	@OUT=`diff $@ $(EXPECTED_DIR)$(shell basename $@)`; \
	if [ -z "$$OUT" ]; then \
		echo -e $(OK_STRING); \
	else \
		echo -e $(ERROR_STRING); \
		echo $$OUT; \
	fi


clean:
	@echo cleaning!
	@/bin/rm -rf $(OUT_DIR)

re: clean all
