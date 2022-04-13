import groovy.transform.Field

@Field List stages = ["source", "config", "prebuild", "build", "postbuild", "test", "blackduck", "release"]
@Field List parallel_stages = ["source", "config", "prebuild", "build", "postbuild"]
@Field List standalone_stages = ["blackduck", "release"]

@Field scm_counts = 1
@Field List scm_types = ["git"]
@Field List scm_urls = ["ssh://psp.sdlc.rd.realtek.com:29418/test/test"]
@Field List scm_credentials = [""]
@Field List scm_branchs = ["sandbox/todd/jcac"]
@Field List scm_dsts = ["source"]

@Field List scm_repo_manifest_files = [""]
@Field List scm_repo_manifest_platforms = [""]
@Field List scm_repo_manifest_depths = [""]
@Field List scm_repo_manifest_currentbranchs = [""]
@Field List scm_repo_manifest_notags = [""]

@Field config_enabled = false
@Field List config_scripts_type = [""]
@Field List config_scripts = [""]

@Field prebuild_enabled = false
@Field List prebuild_scripts_type = [""]
@Field List prebuild_scripts = [""]

@Field build_enabled = true
//@Field build_enabled_script = ""
@Field List build_scripts_type = ["file"]
@Field List build_scripts = ["helloworld.sh"]

@Field postbuild_enabled = false
@Field List postbuild_scripts_type = [""]
@Field List postbuild_scripts = [""]

@Field test_enabled = false
@Field List test_scripts_type = [""]
@Field List test_scripts = [""]

// COVERITY SETTINGS
@Field coverity_scan_enabled = false
// Jenkins environmental credential id, required for coverity scan and report generation
@Field coverity_auth_key_credential = ""
@Field coverity_scan_toolbox=""
@Field coverity_scan_path=""
@Field coverity_xml="coverity_idir/coverity.xml"
@Field coverity_build_dir="coverity_idir/build"
@Field coverity_host="172.21.15.146"
@Field coverity_port="8080"
@Field coverity_stream=""
@Field coverity_comptype_prefix=""
//@Field coverity_comptype_gcc=""
@Field coverity_comptype_gcc=""
@Field coverity_comptype_ld=""
@Field coverity_checker_enablement="default"

// blackduck settings
@Field blackduck_enabled = false
@Field blackduck_url = "https://blackduck.sdlc.rd.realtek.com/"
@Field blackduck_token_credential = ""
@Field blackduck_project_name = ""
@Field blackduck_project_version = ""

// release and unified release flow
@Field release_enabled = false
@Field release_script_type = ""
@Field release_script = ""
@Field release_archive_artifacts = false
@Field release_artifacts_path = ""
@Field release_urf_user = ""
@Field release_urf_token = ""
@Field coverity_report_toolbox = ""
@Field coverity_report_toolpath = ""
@Field coverity_report_config = "rtk_coverity/coverity_report_config.yaml"
@Field unified_release_flow_toolbox=""
@Field List unified_release_flow_coverity_projects = [""]
@Field List unified_release_flow_blackduck_projects = [""]
@Field List unified_release_flow_blackduck_versions = [""]
@Field List unified_release_flow_files = [""]
@Field unified_release_flow_coverity_report = false
@Field unified_release_flow_balckduck_report = false
@Field unified_release_flow_config = ""
@Field unified_release_flow_bom = ""
@Field unified_release_flow = false

// post scripts
@Field List post_scripts_condition = [""]
@Field List post_scripts_type = [""]
@Field List post_scripts = [""]
@Field mail_enabled = false
@Field mail_body = ""
@Field mail_recipient = ""

return this
