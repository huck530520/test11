pipeline {
    agent {
        label "built-in"
    }
    stages {
        stage ("test-1") {
            steps {
                sh """
                   pwd && ls -al
                """
            }
        }
    }
}
