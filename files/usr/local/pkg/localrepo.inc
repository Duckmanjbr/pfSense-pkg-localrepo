<?php
/*
 * localrepo.inc
 *
 * part of pfSense (https://www.pfsense.org)
 * Copyright (c) 2015 Rubicon Communications, LLC (Netgate)
 * Copyright (c) 2008 Mark J Crane
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 define('BASE_DIR','/usr/local/etc/pkg/repos/');
 define('DEFAULT_REPO_CONFIG', BASE_DIR . 'pfSense-repo.conf')
 define('LOCAL_REPO', BASE_DIR . "localrepo")
 define('LOCAL_REPO_CONFIG', BASE_DIR . "localrepoconf")


function get_pkgs() {
	/* Get a list of all available pfSense packages available to download.*/
	global $pkgs;
	if (!is_array($pkgs['name'])) {
		$pkgs['name'] = array();
		$output = shell_exec('pkg search "pfSense-pkg*" | awk '{ print $1 }'');
		$pkgs['name'] = explode(" ", trim($output));
    $pkgs['descr'] = arrey();
    $output = shell_exec('pkg search "pfSense-pkg*" | awk '{ print $2 }'')
    $pkgs['descr'] = explode(" ", trim($output));
		return $pkgs;
	}
}
function create_local_repo_stucture() {
	/* Create local repository structure from options assigned. */
  mkdir("LOCAL_REPO", 0755);
}
function fill_local_repo() {
	/* Downlaod all selected packages into the local repository. */
  exec('pkg update');
  exec('pkg fetch -y -d -o 'LOCAL_REPO' "pfSense-pkg*"');
}
function create_local_repo() {
	/* Create local repository from all remote packages downloaded. */
  exec('pkg repo 'LOCAL_REPO);
  link("/usr/local/bin/localrepo.conf", LOCAL_REPO_CONFIG);
  chmod(LOCAL_REPO_CONFIG, 0755);
  exec('pkg update');
}
function enable_local_repo(){
	/* Enable local repository in pfSense. */
  exec('sed -i -e "s/enabled: no/enabled: yes/g" 'LOCAL_REPO_CONFIG);
}
function enable_pfSense_repos(){
	/* Enable default pfSense repositories. */
  exec('sed -i -e "s/enabled: no/enabled: yes/g" /usr/local/share/pfSense/pkg/repos/pfSense-repo.conf');
}
function disable_local_repo(){
	/* Disable local repository in pfSense. */
  exec('sed -i -e "s/enabled: yes/enabled: no/g" 'LOCAL_REPO_CONFIG);
}
function disable_pfSense_repos(){
	/* Disable default pfSense repositories. */
  exec('sed -i -e "s/enabled: yes/enabled: no/g" /usr/local/share/pfSense/pkg/repos/pfSense-repo.conf');
}
function remove_local_repo(){
	/* Clean-up/Remove local repository from pfSense */
  exec('rm -fR 'LOCAL_REPO_CONFIG LOCAL_REPO);
}


if (($_POST['Submit'] == 'build_repo') {
  remove_local_repo();
  enable_pfSense_repos();
  create_local_repo_stucture();
  fill_local_repo();
  create_local_repo();
}
if (($_POST['Submit'] == 'update_repo') {
  enable_pfSense_repos();
  fill_local_repo();
  exec('pkg update');
}
?>
