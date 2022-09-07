pipeline {
    agent any

    parameters {
        choice(name: "TEST_ENABLED", choices: ["ON", "OFF"], description: "Активирует сборку и запуск тестов.")
        choice(name: "DOCS_ENABLED", choices: ["OFF", "ON"], description: "Активирует генерацию документации.")
    }

    stages {
        stage("Build") {
            steps {
                dir("build") {
                    sh "cmake .. -DTEST_ENABLED=${params.TEST_ENABLED}"
                    sh "make -j`nproc`"
                }
            }
        }

        stage("Test - Unit testing") {
            when { environment name: "TEST_ENABLED", value: "ON" }

            steps {
                dir("build") {
                    sh "make test"
                }
            }
        }

        stage("Info - Generate documentation") {
            when { environment name: "DOCS_ENABLED", value: "ON" }

            steps {
                sh "doxygen"
                sh "mkdir docs && mv html/ docs/"
            }
        }
    }
}
