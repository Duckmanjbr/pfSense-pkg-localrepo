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
 define('BASE_DIR','/usr/local/etc/pkg/repos');
 define('DEFAULT_REPO_CONFIG', BASE_DIR . 'pfSense-repo.conf')
 define('LOCAL_REPO', BASE_DIR . "$reponame")
 define('LOCAL_REPO_CONFIG', BASE_DIR . "$repoconfigfile")


function get_pkgs() {
	/* Get a list of all available pfSense packages available to download.*/
	global $pkgs;
	if (!is_array($pkgs['pkg'])) {
		$pkgs['pkg'] = array();
		$output = shell_exec(pkg search "pfSense-pkg*" | awk '{ print $1 }')
		$pkgs = explode(" ", trim($output));
		return $pkgs;
	}
}
function create_local_repo_stucture() {
	/* Create local repository structure from options assigned. */
}
function fill_local_repo() {
	/* Downlaod all selected packages into the local repository. */
}
function create_local_repo() {
	/* Create local repository from all remote packages downloaded. */
}
function enable_local_repo(){
	/* Enable local repository in pfSense. */
}
function disable_local_repo(){
	/* Disable local repository in pfSense. */
}
function remove_local_repo(){
	/* Clean-up/Remove local repository from pfSense */
}
function disable_pfSense_repos(){
	/* Disable default pfSense repositories. */
}
function enable_pfSense_repos(){
	/* Enable default pfSense repositories. */
}
if (($_POST['Submit'] == 'build_repo') {...}
if (($_POST['Submit'] == 'update_repo') {...}
?>
