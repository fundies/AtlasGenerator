.PHONY: clean All

All:
	@echo "----------Building project:[ AtlasGenerator - Debug ]----------"
	@"$(MAKE)" -f  "AtlasGenerator.mk"
clean:
	@echo "----------Cleaning project:[ AtlasGenerator - Debug ]----------"
	@"$(MAKE)" -f  "AtlasGenerator.mk" clean
