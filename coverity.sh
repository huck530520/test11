/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-configure --config .coverity/config.xml --gcc --template
/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-build --dir .coverity --config .coverity/config.xml gcc reference/submodule/test.c
/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-analyze --dir .coverity
/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-commit-defects --dir .coverity --url http://172.21.15.146:8080 --stream CTCSOC_test_test --auth-key-file ~/auth-key.txt --encryption none
