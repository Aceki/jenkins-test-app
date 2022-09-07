pipeline {
    agent any

    parameters {
        choice(name: "TEST_ENABLED", choices: ["OFF", "ON"], description: "Включает сборку и запуск тестов.")
    }

    options {
        skipDefaultCheckout(true)
    }

    stages {
        stage("Build") {
            steps {
                cleanWs()
                checkout scm
                dir("build") {
                    sh "cmake .. -DTEST_ENABLED=${params.TEST_ENABLED}"
                    sh "make -j`nproc`"
                }
            }
        }

        stage("Test") {
            when { environment name: "TEST_ENABLED", value: "ON" }

            steps {
                dir("build") {
                    sh "make test"
                }
            }
        }
    }

    post {
        always {
            cleanWs(
                cleanWhenNotBuilt: false,
                deleteDirs: true,
                disableDeferredWipeout: true,
                notFailBuild: true,
                patterns: [
                    [pattern: '.gitignore', type: 'INCLUDE'],
                    [pattern: '.propsfile', type: 'EXCLUDE']
                ]
            )
        }
    }
}
