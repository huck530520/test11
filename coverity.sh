/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-configure --config .coverity/config.xml --gcc --template
/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-build --dir .coverity --config .coverity/config.xml sh build.sh
/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-analyze --dir .coverity
/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-commit-defects --dir .coverity --url http://172.21.15.146:8080 --stream CTCSOC_test_test --auth-key-file ~/auth-key.txt --encryption none

/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-commit-defects --dir .coverity --url http://172.21.15.146:8080 --stream CTCSOC_test_test --scm git --auth-key-file /home/reycheng/auth-key.txt --encryption none --preview-report-v2 preview_report_v2.json
/home/reycheng/cov-analysis-linux64-2022.12.0/bin/cov-blame --dir .coverity --preview-report preview_report_v2.json --scm git --owner-assignment-rules line

