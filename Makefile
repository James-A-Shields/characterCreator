.PHONY: clean All

All:
	@echo "----------Building project:[ characterCeator - Debug ]----------"
	@cd "characterCeator" && "$(MAKE)" -f  "characterCeator.mk"
clean:
	@echo "----------Cleaning project:[ characterCeator - Debug ]----------"
	@cd "characterCeator" && "$(MAKE)" -f  "characterCeator.mk" clean
