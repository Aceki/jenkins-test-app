pipeline {
    agent any

    parameters {
        choice(name: "TEST_ENABLED", choices: ["OFF", "ON"], description: "Включает сборки тестов.")
        string(name: "Build directory")
    }

    options {
        skipDefaultCheckout(true)
    }

    stages {
        stage("build") {
            steps {
                cleanWs()
                checkout scm
                sh "mkdir build"
                dir build
                sh "cmake -B build -DTEST_ENABLED=${params.TEST_ENABLED}"
                sh "make -j4 `nproc`"
            }
        }

        stage("test") {
            when { environment name: "TEST_ENABLED", value: "ON" }

            steps {
                sh "make test"
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
